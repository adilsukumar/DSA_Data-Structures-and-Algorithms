#!/usr/bin/env python3
"""
import_codechef.py -- backfill every Accepted CodeChef submission into inbox/.

Unlike LeetCode, this needs NO cookie. CodeChef exposes three endpoints that
are readable without logging in:

    /recent/user?user_handle=X&page=N     paginated submission history
    /api/submission-code/<id>             the submitted source
    /api/contests/PRACTICE/problems/<C>   name, difficulty rating, topic tags

For each problem it keeps the most recent ACCEPTED submission (the code you
ended up with) but records the EARLIEST accepted time as the solve date -- the
moment you actually cracked it.

It writes raw code into inbox/ plus a .url hint carrying the problem name,
difficulty rating, tags and solve date. process_inbox.py then explains and
files each one.

Usage
-----
    python scripts/import_codechef.py --user adilsukumar --dry-run
    python scripts/import_codechef.py --user adilsukumar
    python scripts/import_codechef.py --user adilsukumar --limit 20
"""

import argparse
import re
import sys
import time
from datetime import datetime, timedelta
from pathlib import Path

try:
    import requests
except ImportError:
    print("This script needs `requests`:  pip install requests")
    sys.exit(1)

ROOT = Path(__file__).resolve().parent.parent
INBOX = ROOT / "inbox"
ATTEMPTS = ROOT / "Attempts" / "CodeChef"

RECENT_URL = "https://www.codechef.com/recent/user"
CODE_URL = "https://www.codechef.com/api/submission-code/{0}"
PROBLEM_URL = "https://www.codechef.com/api/contests/PRACTICE/problems/{0}"

REQUEST_PAUSE = 1.0
UA = ("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 "
      "(KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36")

LANG_EXT = {
    "c++": ".cpp", "cpp": ".cpp", "c": ".c", "python": ".py", "python3": ".py",
    "py": ".py", "pypy3": ".py", "java": ".java", "javascript": ".js",
    "kotlin": ".kt", "go": ".go", "rust": ".rs", "c#": ".cs",
}

ROW_RE = re.compile(r"<tr[^>]*>(.*?)</tr>", re.S)
# Note the [^>]* -- CodeChef emits "<td  title=" with TWO spaces, so anything
# assuming a single space silently matches nothing.
TD_TITLE_RE = re.compile(r"<td[^>]*title='([^']*)'")
STATUS_RE = re.compile(r"<span title='([^']*)'")
SOLUTION_RE = re.compile(r"/viewsolution/(\d+)")

VERDICTS = {
    "accepted", "wrong answer", "partially accepted", "compilation error",
    "time limit exceeded", "runtime error", "runtime error(sigsegv)",
    "internal error", "memory limit exceeded",
}


def session():
    s = requests.Session()
    s.headers.update({
        "User-Agent": UA,
        "Accept": "application/json, text/javascript, */*; q=0.01",
        "Referer": "https://www.codechef.com/",
    })
    return s


def parse_time(raw):
    """CodeChef shows absolute times for old rows and relative ones for new.

    Old:  '11:28 PM 21/06/26'  (day/month/2-digit-year)
    New:  '3 hours ago', '2 months ago', 'a day ago'

    Relative values are resolved against now, which is approximate by nature --
    good enough for a solve date on a months-old submission.
    """
    raw = (raw or "").strip()
    if not raw:
        return None

    try:
        return datetime.strptime(raw, "%I:%M %p %d/%m/%y")
    except ValueError:
        pass

    match = re.match(r"(?:(\d+)|a|an)\s+(second|minute|hour|day|week|month|year)s?\s+ago",
                     raw, re.I)
    if not match:
        return None
    amount = int(match.group(1)) if match.group(1) else 1
    unit = match.group(2).lower()
    days = {"second": 0, "minute": 0, "hour": 0, "day": 1,
            "week": 7, "month": 30, "year": 365}[unit]
    hours = {"hour": 1, "minute": 1 / 60.0, "second": 1 / 3600.0}.get(unit, 0)
    return datetime.now() - timedelta(days=amount * days, hours=amount * hours)


def parse_rows(html):
    """Yield one dict per submission row.

    Each row's <td> elements carry their value in a title attribute, in a fixed
    order:  [time, problem code, score, language, "View"]. Reading them
    positionally is sturdier than a bespoke regex per column -- CodeChef's
    markup is inconsistently spaced and the columns move around less than the
    HTML around them does.
    """
    for row in ROW_RE.findall(html):
        sol = SOLUTION_RE.search(row)
        if not sol:
            continue                       # pagination / header row

        titles = TD_TITLE_RE.findall(row)
        if len(titles) < 4:
            continue

        verdict = ""
        for value in STATUS_RE.findall(row):
            if value.lower() in VERDICTS:
                verdict = value.lower()
                break

        yield {
            "id": sol.group(1),
            "problem": titles[1].strip(),
            "verdict": verdict,
            "when": parse_time(titles[0]),
            "lang": titles[3].strip(),
        }


def fetch_page(sess, handle, page, attempts=4):
    delay = REQUEST_PAUSE
    for attempt in range(1, attempts + 1):
        try:
            resp = sess.get(RECENT_URL,
                            params={"user_handle": handle, "page": page},
                            headers={"X-Requested-With": "XMLHttpRequest"},
                            timeout=30)
            if resp.status_code in (403, 429):
                raise requests.HTTPError("throttled {0}".format(resp.status_code))
            resp.raise_for_status()
            return resp.json()
        except Exception as exc:
            if attempt == attempts:
                print("  ! page {0} failed: {1}".format(page, exc))
                return None
            delay = min(delay * 2, 30)
            time.sleep(delay)
    return None


def fetch_code(sess, sid):
    try:
        resp = sess.get(CODE_URL.format(sid), timeout=30)
        resp.raise_for_status()
        data = resp.json().get("data", {})
        return data.get("code", ""), (data.get("language") or {})
    except Exception:
        return "", {}


def fetch_problem(sess, code):
    try:
        resp = sess.get(PROBLEM_URL.format(code), timeout=30)
        resp.raise_for_status()
        return resp.json()
    except Exception:
        return {}


def existing_titles():
    """Normalised titles already filed under CodeChef/, to avoid duplicates."""
    titles = set()
    base = ROOT / "CodeChef"
    if not base.is_dir():
        return titles
    for path in base.rglob("*"):
        if not path.is_file():
            continue
        try:
            head = path.read_text(encoding="utf-8", errors="replace")[:3000]
        except OSError:
            continue
        match = re.search(r"@title\s*:?\s+(.+)", head)
        if match:
            titles.add(normalise(match.group(1)))
        match = re.search(r"@problemcode\s*:?\s+(\S+)", head)
        if match:
            titles.add(normalise(match.group(1)))
        titles.add(normalise(path.stem.split(".", 1)[-1]))
    return titles


def normalise(text):
    return re.sub(r"[^a-z0-9]", "", (text or "").lower())


def slugify(title):
    cleaned = re.sub(r"[^\w\s-]", "", title).strip()
    return re.sub(r"[\s-]+", "_", cleaned) or "Untitled"


def main():
    parser = argparse.ArgumentParser(description="Backfill CodeChef solutions.")
    parser.add_argument("--user", required=True, help="your CodeChef handle")
    parser.add_argument("--limit", type=int, default=0, help="stop after N new problems")
    parser.add_argument("--dry-run", action="store_true")
    parser.add_argument("--audit-only", action="store_true",
                        help="report verdict counts without downloading code")
    parser.add_argument("--max-pages", type=int, default=0, help="0 = all pages")
    args = parser.parse_args()

    sess = session()
    INBOX.mkdir(exist_ok=True)

    first = fetch_page(sess, args.user, 0)
    if not first:
        print("Could not read the submission history for '{0}'.".format(args.user))
        return 1
    max_page = int(first.get("max_page") or 1)
    if args.max_pages:
        max_page = min(max_page, args.max_pages)
    print("{0}: {1} pages of submission history.".format(args.user, max_page))

    # problem code -> {latest accepted id, earliest accepted time, lang}
    best = {}
    verdicts_by_problem = {}
    failed_rows = []
    for page in range(0, max_page):
        payload = first if page == 0 else fetch_page(sess, args.user, page)
        if not payload:
            continue
        for row in parse_rows(payload.get("content", "")):
            if row["problem"]:
                verdicts_by_problem.setdefault(row["problem"], set()).add(
                    row["verdict"] or "unknown")
            if row["problem"] and row["verdict"] and row["verdict"] != "accepted":
                failed_rows.append(row)
            if row["verdict"] != "accepted" or not row["problem"]:
                continue
            code = row["problem"]
            entry = best.setdefault(code, {
                "id": row["id"], "lang": row["lang"],
                "first": row["when"], "last": row["when"],
            })
            # Pages arrive newest-first, so the first sighting is the latest
            # submission and every later sighting is older.
            if row["when"] and (entry["first"] is None or row["when"] < entry["first"]):
                entry["first"] = row["when"]
        if page and page % 10 == 0:
            print("  scanned {0}/{1} pages, {2} solved so far".format(
                page, max_page, len(best)))
        time.sleep(REQUEST_PAUSE)

    partial_only = sorted(
        code for code, verdicts in verdicts_by_problem.items()
        if "partially accepted" in verdicts and "accepted" not in verdicts
    )
    attempted_only = sorted(set(verdicts_by_problem) - set(best) - set(partial_only))
    print("\n{0} distinct problems fully accepted.".format(len(best)))
    print("{0} distinct problems partially accepted only.".format(len(partial_only)))
    print("{0} other distinct problems attempted but never accepted.".format(
        len(attempted_only)))
    if partial_only:
        print("Partial-only codes: {0}".format(", ".join(partial_only)))

    if args.audit_only:
        return 0

    archived = 0
    for row in failed_rows:
        day = row["when"].strftime("%Y-%m-%d") if row["when"] else "Unknown-Date"
        base = ATTEMPTS / day
        existing = list(ATTEMPTS.rglob(row["id"] + ".*")) if ATTEMPTS.exists() else []
        if existing:
            continue
        source, lang_info = fetch_code(sess, row["id"])
        time.sleep(REQUEST_PAUSE)
        if not source.strip():
            continue
        ext = "." + (lang_info.get("extension") or "").lstrip(".") \
            if lang_info.get("extension") else LANG_EXT.get(
                (row["lang"] or "").lower(), ".txt")
        target = base / (row["id"] + "." + slugify(row["problem"]) + ext)
        print("  ~ attempt {0} {1}: {2}".format(
            row["id"], row["problem"], row["verdict"]))
        if not args.dry_run:
            base.mkdir(parents=True, exist_ok=True)
            lines = [
                "Platform: CodeChef", "Submission: " + row["id"],
                "Problem: " + row["problem"], "Verdict: " + row["verdict"],
                "Date: " + day,
                "URL: https://www.codechef.com/problems/" + row["problem"], "",
            ]
            header = "/*\n" + "\n".join(" * " + line for line in lines) + " */\n\n"
            if ext == ".py":
                header = '"""\n' + "\n".join(lines) + '"""\n\n'
            target.write_text(header + source, encoding="utf-8")
        archived += 1

    already = existing_titles()
    imported, skipped = 0, 0

    for code in sorted(best, key=lambda c: best[c]["first"] or datetime.min):
        entry = best[code]
        detail = fetch_problem(sess, code)
        time.sleep(REQUEST_PAUSE)

        name = detail.get("problem_name") or code
        rating = detail.get("difficulty_rating") or 0
        tags = detail.get("user_tags") or detail.get("computed_tags") or []
        if isinstance(tags, str):
            tags = [tags]

        if normalise(name) in already or normalise(code) in already:
            skipped += 1
            continue

        source, lang_info = fetch_code(sess, entry["id"])
        time.sleep(REQUEST_PAUSE)
        if not source.strip():
            print("  ! no code for {0}, skipping".format(code))
            continue

        ext = "." + (lang_info.get("extension") or "").lstrip(".") \
            if lang_info.get("extension") else LANG_EXT.get(
                (entry["lang"] or "").lower(), ".txt")

        solved = entry["first"].strftime("%Y-%m-%d") if entry["first"] else ""
        stem = "{0}.{1}".format(code, slugify(name))

        print("  + {0:<12} {1:<40} rating {2:<5} {3}".format(
            code, name[:40], rating, ", ".join(tags) or "-"))

        if not args.dry_run:
            (INBOX / (stem + ext)).write_text(source, encoding="utf-8")
            (INBOX / (stem + ".url")).write_text(
                "CodeChef problem {0} - {1}\n"
                "Difficulty: {2}\n"
                "Topics: {3}\n"
                "URL: https://www.codechef.com/problems/{0}\n"
                "Solved: {4}\n".format(code, name, rating,
                                       ", ".join(tags) or "-", solved),
                encoding="utf-8")

        imported += 1
        if args.limit and imported >= args.limit:
            print("\nReached --limit {0}.".format(args.limit))
            break

    if args.dry_run:
        print("\n{0} new, {1} already filed. Nothing written (--dry-run).".format(
            imported, skipped))
    else:
        print("\n{0} new problem(s) written to inbox/, {1} attempt(s) archived, "
              "{2} already filed.".format(imported, archived, skipped))
        if imported:
            print("\nNext:  python scripts/process_inbox.py --workers 2")
            print("(filing uses local metadata only; no model is called)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
