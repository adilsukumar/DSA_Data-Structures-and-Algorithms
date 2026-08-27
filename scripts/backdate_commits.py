#!/usr/bin/env python3
"""
backdate_commits.py -- give each backfilled solution a commit dated when it was
actually solved.

The problems pulled in by import_leetcode.py were all committed on one day, even
though they were solved across many weeks. This rewrites that stretch of history
so each solution becomes its own commit, authored at its real LeetCode
submission time. The contribution graph then reflects when the work happened
rather than when the backfill ran.

What it does NOT do is invent activity. Every date comes from an actual
Accepted submission timestamp on your own account, fetched by
scripts/fetch_solve_dates.py.

This REWRITES HISTORY and needs a force push. It therefore:
  - refuses to run on a dirty working tree,
  - tags the current HEAD as a backup before touching anything,
  - uses --force-with-lease so it can never clobber someone else's push.

Usage
-----
    python scripts/backdate_commits.py --base <sha> --dry-run
    python scripts/backdate_commits.py --base <sha>
    python scripts/backdate_commits.py --base <sha> --push

Recovering if it goes wrong:
    git reset --hard backup/pre-backdate-<timestamp>
"""

import argparse
import json
import subprocess
import sys
from datetime import datetime
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DATES_FILE = ROOT / "solve_dates.json"
AUTHOR_NAME = "Adil Sukumar"
AUTHOR_EMAIL = "adilsukumar24@gmail.com"


def git(*args, check=True, env=None):
    full = {}
    if env:
        import os
        full = dict(os.environ)
        full.update(env)
    return subprocess.run(
        ["git"] + list(args), cwd=str(ROOT), capture_output=True, text=True,
        encoding="utf-8", errors="replace", check=check, env=full or None,
    )


def out(*args):
    return git(*args).stdout.strip()


def commit_dated(paths, message, iso_date, dry_run=False):
    """Create one commit with author AND committer date pinned to iso_date.

    GitHub's contribution graph reads the AUTHOR date, but leaving the committer
    date at 'now' makes `git log` order look wrong, so both are set.
    """
    if dry_run:
        print("  [dry] {0:<12} {1}".format(iso_date[:10], message))
        return True

    git("add", "--", *paths)
    if not git("diff", "--staged", "--quiet", check=False).returncode:
        return False        # nothing actually changed for this path

    git("commit", "-m", message, env={
        "GIT_AUTHOR_DATE": iso_date,
        "GIT_COMMITTER_DATE": iso_date,
        "GIT_AUTHOR_NAME": AUTHOR_NAME,
        "GIT_AUTHOR_EMAIL": AUTHOR_EMAIL,
        "GIT_COMMITTER_NAME": AUTHOR_NAME,
        "GIT_COMMITTER_EMAIL": AUTHOR_EMAIL,
    })
    print("  {0}  {1}".format(iso_date[:10], message))
    return True


def main():
    parser = argparse.ArgumentParser(description="Backdate solution commits.")
    parser.add_argument("--base", required=True,
                        help="commit to rebuild history on top of (exclusive)")
    parser.add_argument("--dry-run", action="store_true")
    parser.add_argument("--push", action="store_true",
                        help="force-push (with lease) when finished")
    args = parser.parse_args()

    if not DATES_FILE.exists():
        print("No solve_dates.json -- run scripts/fetch_solve_dates.py first.")
        return 1

    dirty = out("status", "--porcelain")
    if dirty and not args.dry_run:
        print("Working tree is dirty. Commit or stash first:\n" + dirty)
        return 1

    dates = json.loads(DATES_FILE.read_text(encoding="utf-8"))
    base = out("rev-parse", args.base)
    head = out("rev-parse", "HEAD")
    print("Rebuilding {0}..{1}".format(base[:8], head[:8]))

    # Split by CHANGE TYPE, not just filename. Only files this range ADDS are
    # eligible for backdating -- those are the backfilled solutions, which had
    # no commit of their own before now.
    #
    # A file that is merely MODIFIED here (an older solution picking up an
    # @solved tag, say) already has a real commit at its real time. Re-dating
    # that edit to the original solve date would claim the edit happened months
    # before it did, which is a different thing entirely from recording when a
    # problem was solved. Those stay on today's date.
    added, modified = [], []
    for line in out("diff", "--name-status", base, head).splitlines():
        parts = line.split("\t")
        if len(parts) < 2:
            continue
        status, path = parts[0], parts[-1]
        (added if status.startswith("A") else modified).append(path)

    solutions = [f for f in added if f.startswith(("LeetCode/", "CodeChef/"))]
    everything = added + modified
    generated = [f for f in everything if f in ("INDEX.md", "README.md")]
    tooling = [f for f in everything if f not in solutions and f not in generated]

    # Only backdate solutions we actually have a real solve date for.
    def date_for(path):
        for pid, info in dates.items():
            if info["path"] == path:
                return info["iso"], pid
        return None, None

    dated, undated = [], []
    for path in solutions:
        iso, pid = date_for(path)
        (dated if iso else undated).append((path, iso, pid))
    dated.sort(key=lambda row: row[1])

    print("\n{0} solutions with a real solve date, {1} without.".format(
        len(dated), len(undated)))
    if undated:
        print("Undated (will be committed today):")
        for path, _, _ in undated:
            print("  - " + path)

    if not args.dry_run:
        stamp = datetime.now().strftime("%Y%m%d-%H%M%S")
        backup = "backup/pre-backdate-" + stamp
        git("tag", backup, head)
        print("\nBackup tag: {0}   (git reset --hard {0} to undo)".format(backup))
        git("reset", "--soft", base)
        git("reset")            # unstage; we add path by path below

    today = datetime.now().astimezone().isoformat()

    print("\n--- tooling ---")
    if tooling:
        commit_dated(tooling, "chore: repository tooling and fixes", today, args.dry_run)

    print("\n--- solutions, in the order they were solved ---")
    for path, iso, pid in dated:
        title = Path(path).stem.split(".", 1)[-1].replace("_", " ")
        commit_dated([path], "solve: LeetCode {0} - {1}".format(pid, title),
                     iso, args.dry_run)
    for path, _, _ in undated:
        title = Path(path).stem.split(".", 1)[-1].replace("_", " ")
        commit_dated([path], "solve: {0}".format(title), today, args.dry_run)

    print("\n--- generated ---")
    if generated:
        commit_dated(generated, "chore: refresh problem index and statistics",
                     today, args.dry_run)

    if args.dry_run:
        print("\n(--dry-run: history untouched)")
        return 0

    leftover = out("status", "--porcelain")
    if leftover:
        print("\nUncommitted leftovers -- adding them:\n" + leftover)
        commit_dated(["."], "chore: remaining changes", today)

    print("\nNew history:")
    print(out("log", "--format=%h %ad %s", "--date=short", base + "..HEAD"))

    if args.push:
        print("\nForce-pushing (with lease)...")
        result = git("push", "--force-with-lease", check=False)
        print(result.stdout or result.stderr)
    else:
        print("\nNot pushed. When you are happy:  git push --force-with-lease")
    return 0


if __name__ == "__main__":
    sys.exit(main())
