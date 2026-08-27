#!/usr/bin/env python3
"""
import_leetcode.py -- backfill every Accepted LeetCode submission into inbox/.

LeetCode has no public API for your own submissions, so this authenticates as
you using your browser session cookie. Nothing is sent anywhere except to
leetcode.com.

Getting your cookie
-------------------
1. Log in to leetcode.com in your browser.
2. Open DevTools (F12) -> Application -> Cookies -> https://leetcode.com
3. Copy the value of LEETCODE_SESSION (a long token).
4. Put it in a .env file at the repo root:

       LEETCODE_SESSION=eyJ...

   .env is gitignored -- the cookie never gets committed. It is equivalent to
   your login, so do not paste it anywhere else, and log out of LeetCode to
   invalidate it if it leaks.

What it does
------------
- Pages through your submission history.
- Keeps the most recent ACCEPTED submission per problem.
- Skips problems already present in this repo.
- Writes each one to inbox/ alongside a .url hint file holding the title,
  difficulty and official topic tags pulled from LeetCode.

It does NOT write explanations. Run process_inbox.py afterwards for that:

    python scripts/import_leetcode.py --limit 20
    python scripts/process_inbox.py

Usage
-----
    python scripts/import_leetcode.py                 # fetch everything new
    python scripts/import_leetcode.py --limit 20      # only the 20 most recent
    python scripts/import_leetcode.py --dry-run       # list, write nothing
"""

import argparse
import json
import os
import re
import sys
import time
from pathlib import Path

try:
    import requests
except ImportError:
    print("This script needs `requests`:  pip install requests")
    sys.exit(1)

ROOT = Path(__file__).resolve().parent.parent
INBOX = ROOT / "inbox"
ENV_FILE = ROOT / ".env"

SUBMISSIONS_URL = "https://leetcode.com/api/submissions/"
GRAPHQL_URL = "https://leetcode.com/graphql"
PAGE_SIZE = 20
REQUEST_PAUSE = 1.0          # be polite; LeetCode throttles aggressively

LANG_EXT = {
    "cpp": ".cpp", "c": ".c", "python": ".py", "python3": ".py",
    "java": ".java", "javascript": ".js", "typescript": ".ts",
    "golang": ".go", "rust": ".rs", "kotlin": ".kt", "csharp": ".cs",
    "ruby": ".rb", "swift": ".swift", "scala": ".scala", "php": ".php",
}

QUESTION_QUERY = """
query getQuestionDetail($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    questionFrontendId
    title
    titleSlug
    difficulty
    topicTags { name }
  }
}
"""


def load_session():
    """Read LEETCODE_SESSION from the environment or the .env file."""
    token = os.environ.get("LEETCODE_SESSION", "").strip()
    if token:
        return token

    if ENV_FILE.exists():
        for line in ENV_FILE.read_text(encoding="utf-8").splitlines():
            line = line.strip()
            if line.startswith("#") or "=" not in line:
                continue
            key, _, value = line.partition("=")
            if key.strip() == "LEETCODE_SESSION":
                return value.strip().strip('"').strip("'")
    return ""


def make_session(token):
    session = requests.Session()
    session.cookies.set("LEETCODE_SESSION", token, domain="leetcode.com")
    session.headers.update({
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64)",
        "Referer": "https://leetcode.com/submissions/",
        "Accept": "application/json",
    })
    return session


def fetch_submissions(session, max_pages=200):
    """Page through the submission history, newest first."""
    offset, seen_pages = 0, 0
    while seen_pages < max_pages:
        response = session.get(
            SUBMISSIONS_URL, params={"offset": offset, "limit": PAGE_SIZE},
            timeout=30,
        )
        if response.status_code == 403:
            raise SystemExit(
                "LeetCode returned 403. Your LEETCODE_SESSION is expired or wrong.\n"
                "Log in again and copy a fresh cookie into .env."
            )
        response.raise_for_status()

        try:
            payload = response.json()
        except json.JSONDecodeError:
            raise SystemExit(
                "LeetCode returned HTML instead of JSON -- almost always an "
                "invalid or expired session cookie."
            )

        batch = payload.get("submissions_dump", [])
        if not batch:
            return

        for item in batch:
            yield item

        if not payload.get("has_next"):
            return

        offset += PAGE_SIZE
        seen_pages += 1
        time.sleep(REQUEST_PAUSE)


def fetch_question(session, slug):
    """Difficulty and official topic tags for a problem (no auth needed)."""
    try:
        response = session.post(
            GRAPHQL_URL,
            json={"query": QUESTION_QUERY, "variables": {"titleSlug": slug}},
            timeout=30,
        )
        response.raise_for_status()
        return response.json().get("data", {}).get("question") or {}
    except Exception:
        return {}


def existing_problem_ids():
    """LeetCode ids already filed in the repo, read from the @id headers."""
    found = set()
    base = ROOT / "LeetCode"
    if not base.is_dir():
        return found
    for path in base.rglob("*"):
        if not path.is_file():
            continue
        match = re.match(r"^(\d+)\.", path.name)
        if match:
            found.add(match.group(1))
    return found


def slugify(title):
    cleaned = re.sub(r"[^\w\s-]", "", title).strip()
    return re.sub(r"[\s-]+", "_", cleaned) or "Untitled"


def main():
    parser = argparse.ArgumentParser(description="Backfill LeetCode solutions into inbox/.")
    parser.add_argument("--limit", type=int, default=0,
                        help="stop after N new problems (0 = no limit)")
    parser.add_argument("--dry-run", action="store_true",
                        help="list what would be imported, write nothing")
    args = parser.parse_args()

    token = load_session()
    if not token:
        print("No LEETCODE_SESSION found.\n")
        print("Create a .env file at the repo root containing:\n")
        print("    LEETCODE_SESSION=<your cookie value>\n")
        print("See the docstring at the top of this file for how to get it.")
        return 1

    session = make_session(token)
    already = existing_problem_ids()
    print("{0} problem(s) already in the repo.".format(len(already)))

    INBOX.mkdir(exist_ok=True)

    imported, skipped, seen_slugs = 0, 0, set()

    for sub in fetch_submissions(session):
        if sub.get("status_display") != "Accepted":
            continue

        slug = sub.get("title_slug") or ""
        if not slug or slug in seen_slugs:
            continue          # keep only the most recent accept per problem
        seen_slugs.add(slug)

        detail = fetch_question(session, slug)
        time.sleep(REQUEST_PAUSE)

        pid = str(detail.get("questionFrontendId") or "").strip()
        title = detail.get("title") or sub.get("title") or slug
        difficulty = detail.get("difficulty") or "Easy"
        topics = [t["name"] for t in (detail.get("topicTags") or [])]

        if pid and pid in already:
            skipped += 1
            continue

        ext = LANG_EXT.get(sub.get("lang", ""), ".txt")
        code = sub.get("code") or ""
        if not code.strip():
            print("  ! no code returned for {0}, skipping".format(title))
            continue

        stem = "{0}.{1}".format(pid or "x", slugify(title))
        target = INBOX / (stem + ext)
        hint = INBOX / (stem + ".url")

        print("  + {0} {1} [{2}] {3}".format(
            pid or "?", title, difficulty, ", ".join(topics) or "-"))

        if not args.dry_run:
            target.write_text(code, encoding="utf-8")
            hint.write_text(
                "LeetCode {0} - {1}\n"
                "Difficulty: {2}\n"
                "Topics: {3}\n"
                "URL: https://leetcode.com/problems/{4}/\n".format(
                    pid, title, difficulty, ", ".join(topics), slug),
                encoding="utf-8",
            )

        imported += 1
        if args.limit and imported >= args.limit:
            print("\nReached --limit {0}.".format(args.limit))
            break

    print("\n{0} new problem(s) written to inbox/, {1} already present.".format(
        imported, skipped))
    if imported and not args.dry_run:
        print("\nNext:  python scripts/process_inbox.py")
        print("(that is one Claude call per problem -- consider batches of ~20)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
