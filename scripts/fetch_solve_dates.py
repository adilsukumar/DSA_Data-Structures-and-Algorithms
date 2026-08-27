#!/usr/bin/env python3
"""
fetch_solve_dates.py -- record when each problem was actually solved.

Reads your LeetCode submission history and, for every problem already filed in
this repo, finds the EARLIEST Accepted submission -- the moment you genuinely
solved it, not the last time you re-submitted. That date is written into the
solution file as an `@solved` tag, so it becomes part of the permanent record
and shows up in INDEX.md.

The dates are also written to a JSON file, which scripts/backdate_commits.py
uses to give each solution a commit dated when the work really happened.

Usage
-----
    python scripts/fetch_solve_dates.py                # tag files + write JSON
    python scripts/fetch_solve_dates.py --dry-run      # show dates, change nothing
    python scripts/fetch_solve_dates.py --out x.json   # custom JSON path

Needs LEETCODE_SESSION in .env, same as import_leetcode.py.
"""

import argparse
import json
import re
import sys
import time
from datetime import datetime, timezone
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from import_leetcode import (  # noqa: E402  (path set up above)
    REQUEST_PAUSE,
    RateLimited,
    fetch_submissions,
    load_env,
    make_session,
)

ROOT = Path(__file__).resolve().parent.parent
DEFAULT_OUT = ROOT / "solve_dates.json"
SOLUTION_SUFFIXES = {".cpp", ".py", ".java", ".js", ".c", ".go", ".rs", ".kt", ".ts"}


def repo_solutions():
    """Map LeetCode problem id -> the file holding it."""
    found = {}
    base = ROOT / "LeetCode"
    if not base.is_dir():
        return found
    for path in sorted(base.rglob("*")):
        if path.is_file() and path.suffix in SOLUTION_SUFFIXES:
            match = re.match(r"^(\d+)\.", path.name)
            if match:
                found[match.group(1)] = path
    return found


def earliest_accepts(session):
    """slug -> earliest accepted unix timestamp, across the whole history."""
    earliest = {}
    count = 0
    try:
        for sub in fetch_submissions(session):
            count += 1
            if sub.get("status_display") != "Accepted":
                continue
            slug = sub.get("title_slug") or ""
            stamp = int(sub.get("timestamp") or 0)
            if not slug or not stamp:
                continue
            # History arrives newest-first, so later writes are always older.
            if slug not in earliest or stamp < earliest[slug]:
                earliest[slug] = stamp
    except RateLimited as exc:
        print("Stopped early ({0}). Dates gathered so far are still usable.".format(exc))
    print("Scanned {0} submissions, {1} distinct problems accepted.".format(
        count, len(earliest)))
    return earliest


def slug_to_id(session, slugs):
    """Resolve each slug to its LeetCode problem number."""
    from import_leetcode import fetch_question

    mapping = {}
    for i, slug in enumerate(sorted(slugs), 1):
        detail = fetch_question(session, slug)
        pid = str(detail.get("questionFrontendId") or "").strip()
        if pid:
            mapping[slug] = pid
        if i % 10 == 0:
            print("  resolved {0}/{1}".format(i, len(slugs)))
        time.sleep(REQUEST_PAUSE)
    return mapping


def tag_file(path, date_str, dry_run=False):
    """Insert or update the `@solved` line in a file's @tag block."""
    text = path.read_text(encoding="utf-8")

    if re.search(r"@solved\s", text):
        updated = re.sub(r"(@solved\s*:?\s+)\S+", r"\g<1>" + date_str, text, count=1)
        action = "updated"
    else:
        # Slot it in directly after @url, copying that line's comment prefix so
        # the block stays visually aligned whatever the comment syntax is.
        match = re.search(r"^([^\S\n]*\S*\s*)@url(\s+)(\S*)[^\n]*$", text, re.M)
        if not match:
            return None
        prefix, gap = match.group(1), match.group(2)
        # "@url        " is 4 chars wider than "@solved", so trim to keep the
        # value column lined up.
        solved_gap = gap[:-3] if len(gap) > 3 else " "
        insertion = "\n{0}@solved{1}{2}".format(prefix, solved_gap, date_str)
        updated = text[:match.end()] + insertion + text[match.end():]
        action = "added"

    if not dry_run:
        path.write_text(updated, encoding="utf-8")
    return action


def main():
    parser = argparse.ArgumentParser(description="Record real solve dates.")
    parser.add_argument("--dry-run", action="store_true")
    parser.add_argument("--out", default=str(DEFAULT_OUT))
    args = parser.parse_args()

    token = load_env("LEETCODE_SESSION")
    if not token:
        print("No LEETCODE_SESSION in .env -- see .env.example.")
        return 1

    session = make_session(token)
    solutions = repo_solutions()
    print("{0} LeetCode solutions in the repo.".format(len(solutions)))

    print("\nScanning submission history for earliest accepts...")
    earliest = earliest_accepts(session)
    if not earliest:
        print("No accepted submissions found.")
        return 1

    print("\nResolving problem numbers...")
    mapping = slug_to_id(session, earliest.keys())

    dates, tagged = {}, 0
    for slug, pid in mapping.items():
        if pid not in solutions:
            continue
        stamp = earliest[slug]
        when = datetime.fromtimestamp(stamp, tz=timezone.utc)
        dates[pid] = {
            "date": when.strftime("%Y-%m-%d"),
            "iso": when.isoformat(),
            "timestamp": stamp,
            "slug": slug,
            "path": solutions[pid].relative_to(ROOT).as_posix(),
        }
        action = tag_file(solutions[pid], when.strftime("%Y-%m-%d"), args.dry_run)
        if action:
            tagged += 1

    out = Path(args.out)
    if not args.dry_run:
        out.write_text(json.dumps(dates, indent=2, sort_keys=True), encoding="utf-8")

    print("\n{0} solve dates matched to files, {1} tagged with @solved.".format(
        len(dates), tagged))
    for pid in sorted(dates, key=lambda k: dates[k]["timestamp"]):
        print("  {0}  #{1:<5} {2}".format(
            dates[pid]["date"], pid, Path(dates[pid]["path"]).name))
    if args.dry_run:
        print("\n(--dry-run: nothing written)")
    else:
        print("\nWrote {0}".format(out.relative_to(ROOT).as_posix()))
    return 0


if __name__ == "__main__":
    sys.exit(main())
