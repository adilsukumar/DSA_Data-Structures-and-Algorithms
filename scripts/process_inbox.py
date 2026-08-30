#!/usr/bin/env python3
"""
process_inbox.py -- the daily solution pipeline.

Drop a raw solution file into inbox/. This script then, for each file:

  1. Reads trusted metadata written by the platform importer.
  2. Files the solution into the right platform/difficulty folder with the
     repo's naming convention.
  3. Rebuilds INDEX.md and the README statistics.
  4. Commits everything as YOU (not a bot, so it counts toward your streak)
     and pushes.

Usage
-----
    python scripts/process_inbox.py               # process inbox/, commit, push
    python scripts/process_inbox.py --dry-run     # show what would happen
    python scripts/process_inbox.py --no-push     # commit locally only
    python scripts/process_inbox.py --file x.cpp  # process one specific file
    python scripts/process_inbox.py --workers 5   # process 5 files at a time

No AI model or model CLI is used. Explanations are marked for manual review.

A file is left in inbox/ untouched if anything about it fails, so nothing is
ever lost. Re-run the script after fixing the problem.
"""

import argparse
import re
import subprocess
import sys
import threading
from concurrent.futures import ThreadPoolExecutor, as_completed
from datetime import datetime
from pathlib import Path

# Serialises the "pick a destination path and write to it" step. Files can be
# processed in parallel, but CodeChef filenames are numbered by scanning the target
# folder, so two threads landing there at once would pick the same number.
PLACEMENT_LOCK = threading.Lock()
PRINT_LOCK = threading.Lock()

ROOT = Path(__file__).resolve().parent.parent
INBOX = ROOT / "inbox"
FAILED = INBOX / "_failed"

EXT_LANG = {
    ".cpp": "C++", ".cc": "C++", ".py": "Python", ".java": "Java",
    ".js": "JavaScript", ".ts": "TypeScript", ".c": "C", ".go": "Go",
    ".rs": "Rust", ".kt": "Kotlin",
}

# Rating -> the CodeChef folder name this repo already uses.
CODECHEF_BUCKETS = [
    (500, "500_Difficulty_Rating"),
    (1000, "500_to_1000_Difficulty_Rating"),
    (1400, "1000_to_1400_Difficulty_Rating"),
    (1600, "1400_to_1600_Difficulty_Rating"),
    (1800, "1600_to_1800_Difficulty_Rating"),
    (2000, "1800_to_2000_Difficulty_Rating"),
    (2500, "2000_to_2500_Difficulty_Rating"),
]

def log(msg):
    print(msg, flush=True)


def slugify(title):
    """'Two Sum' -> 'Two_Sum' (matches this repo's existing file naming)."""
    cleaned = re.sub(r"[^\w\s-]", "", title).strip()
    return re.sub(r"[\s-]+", "_", cleaned) or "Untitled"


def codechef_folder(difficulty):
    try:
        rating = int(re.sub(r"[^\d]", "", str(difficulty)) or 0)
    except ValueError:
        rating = 0
    for ceiling, name in CODECHEF_BUCKETS:
        if rating <= ceiling:
            return name
    return CODECHEF_BUCKETS[-1][1]


def next_sequence(folder):
    """CodeChef files are numbered per folder, so find the next free number."""
    highest = 0
    if folder.is_dir():
        for path in folder.iterdir():
            match = re.match(r"^(\d+)\.", path.name)
            if match:
                highest = max(highest, int(match.group(1)))
    return highest + 1


def destination(meta, suffix):
    """Work out where this solution belongs in the repo tree."""
    platform = (meta.get("platform") or "LeetCode").strip()

    if platform.lower() == "codechef":
        folder = ROOT / "CodeChef" / codechef_folder(meta.get("difficulty"))
        number = next_sequence(folder)
    else:
        difficulty = (meta.get("difficulty") or "Easy").strip().capitalize()
        if difficulty not in ("Easy", "Medium", "Hard"):
            difficulty = "Easy"
        folder = ROOT / "LeetCode" / difficulty
        raw_id = re.sub(r"[^\d]", "", str(meta.get("id") or ""))
        number = raw_id or next_sequence(folder)

    folder.mkdir(parents=True, exist_ok=True)
    return folder / "{0}.{1}{2}".format(number, slugify(meta.get("title", "")), suffix)


def metadata_from_hint(path, hint):
    """Read importer-provided facts without calling any model."""
    first = hint.splitlines()[0] if hint else path.stem.replace("_", " ")
    lc = re.match(r"LeetCode\s+(\S*)\s+-\s+(.+)", first)
    cc = re.match(r"CodeChef problem\s+(\S+)\s+-\s+(.+)", first)
    if lc:
        platform, pid, title = "LeetCode", lc.group(1), lc.group(2)
    elif cc:
        platform, pid, title = "CodeChef", cc.group(1), cc.group(2)
    else:
        platform = "CodeChef" if "codechef" in hint.lower() else "LeetCode"
        pid, title = "", path.stem.split(".", 1)[-1].replace("_", " ")

    def field(name, default=""):
        match = re.search(r"^{0}:\s*(.*)$".format(re.escape(name)), hint, re.M | re.I)
        return match.group(1).strip() if match else default

    return {
        "platform": platform, "id": pid, "title": title,
        "difficulty": field("Difficulty", "Easy" if platform == "LeetCode" else "0"),
        "topics": [x.strip() for x in field("Topics").split(",") if x.strip()],
        "pattern": "Pending manual review", "url": field("URL"),
    }


def factual_header(meta, solved_on, suffix):
    """Create a metadata-only header; explanations are intentionally manual."""
    topics = ", ".join(meta.get("topics") or []) or "Unclassified"
    lines = [
        "{0} {1} - {2} [{3}]".format(
            meta["platform"], meta.get("id", ""), meta["title"], meta["difficulty"]),
        "", "@platform   " + meta["platform"], "@id         " + meta.get("id", ""),
        "@title      " + meta["title"], "@difficulty " + str(meta["difficulty"]),
        "@topics     " + topics, "@pattern    Pending manual review",
        "@url        " + meta.get("url", ""), "@solved     " + solved_on,
        "", "Problem", "Accepted solution for " + meta["title"] + ".",
        "", "Approach", "Pending manual review. The submitted code is preserved exactly below.",
        "", "Complexity", "Pending manual review.",
    ]
    if suffix == ".py":
        return '"""\n' + "\n".join(lines) + '\n"""'
    return "/*\n" + "\n".join(" * " + line if line else " *" for line in lines) + "\n */"


def process_one(path, dry_run=False):
    """File one inbox solution using importer metadata only.

    Returns the destination Path, or None on failure. Output is collected in a
    local buffer and flushed as one block, so parallel workers cannot
    interleave half-lines of each other's progress.
    """
    out = ["-> {0}".format(path.name)]

    def log(msg):
        out.append(msg)

    def flush():
        with PRINT_LOCK:
            print("\n" + "\n".join(out), flush=True)

    code = path.read_text(encoding="utf-8", errors="replace").strip()
    if not code:
        log("  ! empty file, skipping")
        flush()
        return None

    suffix = path.suffix.lower()

    # A sibling .url or .txt file, or a leading URL comment, pins down the
    # problem when the code alone is ambiguous.
    hint = ""
    hint_file = path.with_suffix(".url")
    if hint_file.exists():
        hint = hint_file.read_text(encoding="utf-8", errors="replace").strip()
    data = metadata_from_hint(path, hint)

    if dry_run:
        log("  (dry run) would file this solution from local metadata")
        flush()
        return None

    # A backfilled problem was solved long before it was filed. When the
    # importer recorded the real date in the hint, use that; only a genuinely
    # new solution gets today's date.
    solved_on = datetime.now().strftime("%Y-%m-%d")
    hint_date = re.search(r"^Solved:\s*(\d{4}-\d{2}-\d{2})", hint, re.M) if hint else None
    if hint_date:
        solved_on = hint_date.group(1)
    header = factual_header(data, solved_on, suffix)

    dest = destination(data, suffix)
    if dest.exists():
        log("  ! {0} already exists; leaving file in inbox".format(dest.name))
        return None

    dest.write_text(header + "\n\n" + code + "\n", encoding="utf-8")
    path.unlink()
    if hint_file.exists():
        hint_file.unlink()

    topics = ", ".join(data.get("topics") or []) or "-"
    log("  ok  {0}".format(dest.relative_to(ROOT).as_posix()))
    log("      {0} {1} | {2}".format(
        data.get("platform", "?"), data.get("difficulty", "?"), topics))
    flush()
    return dest


def git(*args, check=True):
    return subprocess.run(
        ["git"] + list(args), cwd=str(ROOT), capture_output=True,
        text=True, encoding="utf-8", errors="replace", check=check,
    )


def refresh_generated_files():
    for script in ("build_index.py", "update_stats.py"):
        target = ROOT / "scripts" / script
        if not target.exists():
            continue
        result = subprocess.run(
            [sys.executable, str(target)], cwd=str(ROOT),
            capture_output=True, text=True, encoding="utf-8", errors="replace",
        )
        if result.returncode != 0:
            log("  ! {0} failed: {1}".format(script, result.stderr[:300]))
        else:
            log("  {0}: {1}".format(script, result.stdout.strip().splitlines()[0]
                                    if result.stdout.strip() else "done"))


def commit_and_push(added, push=True):
    # Stage ONLY what this run produced: the solution files it filed, plus the
    # two generated files. `git add -A` would sweep in whatever else happened
    # to be in the working tree -- half-finished edits, scratch files -- and
    # bury them inside a "solve:" commit. An unattended nightly job must never
    # commit work the user did not hand it.
    paths = [p.relative_to(ROOT).as_posix() for p in added]
    for generated in ("INDEX.md", "README.md"):
        if (ROOT / generated).exists():
            paths.append(generated)

    git("add", "--", *paths)

    if not git("diff", "--staged", "--quiet", check=False).returncode:
        log("\nNothing staged -- no commit made.")
        return

    if len(added) == 1:
        subject = "solve: {0}".format(added[0].stem.replace("_", " "))
    else:
        subject = "solve: {0} problems ({1})".format(
            len(added), datetime.now().strftime("%d %b %Y"))

    body = "\n".join("- " + p.relative_to(ROOT).as_posix() for p in added)
    message = subject if not body else subject + "\n\n" + body

    git("commit", "-m", message)
    log("\nCommitted: {0}".format(subject))

    if not push:
        log("(--no-push: not pushing)")
        return

    result = git("push", check=False)
    if result.returncode == 0:
        log("Pushed to origin.")
    else:
        log("! Push failed -- the commit is safe locally. Run `git push` yourself.")
        log("  " + (result.stderr or "").strip()[:300])


def main():
    parser = argparse.ArgumentParser(description="Explain, file, and commit solutions.")
    parser.add_argument("--dry-run", action="store_true", help="show actions only")
    parser.add_argument("--no-push", action="store_true", help="commit but do not push")
    parser.add_argument("--file", help="process a single file instead of the inbox")
    parser.add_argument("--workers", type=int, default=2,
                        help="parallel local file operations (default 2)")
    args = parser.parse_args()

    INBOX.mkdir(exist_ok=True)

    if args.file:
        one = Path(args.file)
        if not one.is_absolute():
            one = ROOT / one
        if not one.exists():
            log("No such file: {0}".format(one))
            return 1
        pending = [one]
    else:
        pending = sorted(
            p for p in INBOX.iterdir()
            if p.is_file() and p.suffix.lower() in EXT_LANG
        )

    if not pending:
        log("Inbox is empty -- nothing to do.")
        return 0

    log("Found {0} solution(s) to process.".format(len(pending)))

    workers = max(1, min(args.workers, len(pending)))
    if workers > 1:
        log("Processing {0} files in parallel.".format(workers))

    def safely(path):
        """One file's work, isolated so a single failure cannot stop the batch."""
        try:
            return process_one(path, dry_run=args.dry_run)
        except Exception as exc:
            with PRINT_LOCK:
                print("  ! unexpected error on {0}: {1}".format(path.name, exc),
                      flush=True)
            return None

    added = []
    if workers == 1:
        for path in pending:
            dest = safely(path)
            if dest:
                added.append(dest)
    else:
        with ThreadPoolExecutor(max_workers=workers) as pool:
            futures = {pool.submit(safely, path): path for path in pending}
            for future in as_completed(futures):
                dest = future.result()
                if dest:
                    added.append(dest)

    added.sort()

    if args.dry_run:
        return 0

    if not added:
        log("\nNothing was filed. Files remain in inbox/ for a retry.")
        return 1

    log("\nRefreshing INDEX.md and README stats...")
    refresh_generated_files()
    commit_and_push(added, push=not args.no_push)
    return 0


if __name__ == "__main__":
    sys.exit(main())
