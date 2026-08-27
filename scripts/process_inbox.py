#!/usr/bin/env python3
"""
process_inbox.py -- the daily solution pipeline.

Drop a raw solution file into inbox/. This script then, for each file:

  1. Asks Claude (via the `claude -p` headless CLI) to identify the problem and
     write an interview-prep explanation header.
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
    python scripts/process_inbox.py --workers 5   # 5 Claude calls at a time

Each solution costs one Claude call, and a call takes a couple of minutes, so
a large backfill runs them in parallel (default 3 at a time). Use --workers 1
to force serial execution when debugging.

A file is left in inbox/ untouched if anything about it fails, so nothing is
ever lost. Re-run the script after fixing the problem.
"""

import argparse
import json
import re
import shutil
import subprocess
import sys
import tempfile
import threading
from concurrent.futures import ThreadPoolExecutor, as_completed
from datetime import datetime
from pathlib import Path

# Serialises the "pick a destination path and write to it" step. Claude calls
# run in parallel, but CodeChef filenames are numbered by scanning the target
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

PROMPT_TEMPLATE = """\
You are documenting a competitive-programming solution for a personal DSA \
repository. The author will re-read these files months later to revise for \
interviews, so the explanation must teach, not just describe.

Here is the solution file the author wrote:

FILENAME: {filename}
```
{code}
```
{hint_block}
Identify which LeetCode or CodeChef problem this solves, then produce an \
explanation header.

Reply with EXACTLY TWO fenced blocks and no other prose.

Block 1 -- a ```json fence holding only short, single-line metadata values:

- "platform"   : "LeetCode" or "CodeChef"
- "id"         : problem number as a string (LeetCode) or "" if unknown
- "title"      : official problem title, Title Case
- "difficulty" : "Easy" | "Medium" | "Hard" for LeetCode; the numeric rating \
as a string (e.g. "800") for CodeChef
- "topics"     : array of standard topic tags, e.g. ["Array","Hash Table"]. \
Use the platform's own tag vocabulary.
- "pattern"    : short name for the technique THIS code uses, under 45 chars
- "url"        : canonical problem URL, or "" if you are not certain

Block 2 -- a ```header fence holding the explanation comment block as RAW TEXT. \
Do not JSON-encode it and do not escape newlines; write it exactly as it should \
appear in the file.

The header must be a complete comment block in {lang}'s comment syntax \
({comment_hint}), ready to sit directly above the code. Follow this structure \
exactly, matching the style of the existing files in this repo:

  - A ruled title line: "{platform_placeholder} <id> - <title>" and difficulty
  - The @tag metadata block, one tag per line, values aligned in a column, \
and with NO colon after the tag name. Exactly this shape:
        @platform   LeetCode
        @id         217
        @title      Contains Duplicate
        @difficulty Easy
        @topics     Array, Hash Table
        @pattern    Hash Set Membership
        @url        https://leetcode.com/problems/contains-duplicate/
  - PROBLEM      : restate it plainly, with a small worked example
  - INTUITION    : the key idea, and WHY it works
  - WALKTHROUGH  : step through THIS code line by line, then a dry run on a \
concrete input showing intermediate state
  - COMPLEXITY   : time and space, each with a one-line justification
  - EDGE CASES   : what could break it, and how the code handles it
  - A final section flagging a better/optimal approach with a short code \
sketch, IF this solution is not already optimal. Omit if it is optimal.

Be specific and honest. If the code has a bug, dead code, or violates the \
problem's stated complexity requirement, say so plainly in the header. Aim for \
60-110 lines. Do not restate the code itself as prose; explain why it works.

Do not repeat the solution code in the header block -- the header sits directly \
above the real code, so duplicating it is noise.
"""


def log(msg):
    print(msg, flush=True)


def claude_executable():
    """Locate the Claude Code CLI.

    On Windows the PATH entry is a `claude.CMD` shim; a bare "claude" in an
    argv list is not resolvable by CreateProcess, so the full path found by
    shutil.which is what actually works here.
    """
    for name in ("claude", "claude.cmd", "claude.exe"):
        found = shutil.which(name)
        if found:
            return found
    return None


_ISOLATED_DIR = None


def isolated_cwd():
    """An empty scratch directory to run the Claude subprocess in.

    Kept outside the repo so the subprocess finds no CLAUDE.md, no slash
    commands and no source tree to explore -- it should answer the prompt it
    was handed, nothing else.
    """
    global _ISOLATED_DIR
    if _ISOLATED_DIR is None:
        _ISOLATED_DIR = Path(tempfile.mkdtemp(prefix="dsa-explain-"))
    return _ISOLATED_DIR


def run_claude(prompt, timeout=420):
    """Call the headless Claude CLI. Returns stdout text, or None on failure."""
    exe = claude_executable()
    if not exe:
        log("  ! `claude` CLI not found on PATH. Install Claude Code or add it.")
        return None

    # The prompt goes in on STDIN, not as an argv element. On Windows the PATH
    # entry is a .CMD shim routed through cmd.exe, which caps a command line at
    # 8191 characters -- and prompt + solution code blows past that, which made
    # calls die with a bare "exited 1" and no stderr.
    #
    # cwd is an EMPTY scratch directory rather than the repo. Run inside the
    # repo, the subprocess auto-discovers CLAUDE.md and the /solved command,
    # decides it is being asked to help with the project, and replies "which
    # solution do you want documented?" instead of doing the transform. With no
    # project around it, the prompt is all there is to respond to.
    try:
        proc = subprocess.run(
            [exe, "-p"], input=prompt,
            capture_output=True, text=True, timeout=timeout,
            encoding="utf-8", errors="replace", cwd=str(isolated_cwd()),
        )
    except FileNotFoundError:
        log("  ! could not execute {0}".format(exe))
        return None
    except subprocess.TimeoutExpired:
        log("  ! claude timed out after {0}s".format(timeout))
        return None

    if proc.returncode != 0:
        log("  ! claude exited {0}: {1}".format(proc.returncode, proc.stderr[:400]))
        return None
    return proc.stdout


def parse_response(text):
    """Split Claude's reply into (metadata dict, header text).

    The two are kept in SEPARATE fences on purpose. Embedding a 100-line comment
    block inside a JSON string means the model has to escape every newline, and
    it reliably gets that wrong. Raw text in its own fence sidesteps the issue.
    """
    if not text:
        return None, None

    # --- metadata ---
    meta = None
    blobs = re.findall(r"```json\s*(\{.*?\})\s*```", text, re.DOTALL)
    if not blobs:
        first, last = text.find("{"), text.find("}")
        if first != -1 and last > first:
            blobs = [text[first:last + 1]]
    for blob in blobs:
        try:
            candidate = json.loads(blob)
        except json.JSONDecodeError:
            continue
        if isinstance(candidate, dict) and candidate.get("title"):
            meta = candidate
            break

    # --- header ---
    header = None
    fenced = re.findall(r"```header\s*\n(.*?)```", text, re.DOTALL)
    if fenced:
        header = fenced[-1]
    else:
        # Fall back to any fence that looks like a comment block.
        for body in re.findall(r"```[a-zA-Z]*\s*\n(.*?)```", text, re.DOTALL):
            stripped = body.lstrip()
            if stripped.startswith("/*") or stripped.startswith('"""'):
                header = body
                break

    return meta, (header.strip() if header else None)


def ensure_solved_tag(header, date_str):
    """Add `@solved <date>` to the header's tag block if it is missing.

    Done here rather than asked of the model: the date a problem was filed is a
    fact this script already knows, and generated metadata is one more thing
    that can come back wrong. The value column is kept aligned with @url.
    """
    if re.search(r"@solved\s", header):
        return header

    match = re.search(r"^([^\S\n]*\S*\s*)@url(\s+)(\S*)[^\n]*$", header, re.M)
    if not match:
        return header

    prefix, gap = match.group(1), match.group(2)
    # "@url" is 3 characters shorter than "@solved", so trim the gap to match.
    solved_gap = gap[:-3] if len(gap) > 3 else " "
    insertion = "\n{0}@solved{1}{2}".format(prefix, solved_gap, date_str)
    return header[:match.end()] + insertion + header[match.end():]


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


def process_one(path, dry_run=False):
    """Explain one inbox file and move it into place.

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
    lang = EXT_LANG.get(suffix, "the source")
    comment_hint = '"""..."""' if suffix == ".py" else "/* ... */"

    # A sibling .url or .txt file, or a leading URL comment, pins down the
    # problem when the code alone is ambiguous.
    hint = ""
    hint_file = path.with_suffix(".url")
    if hint_file.exists():
        hint = hint_file.read_text(encoding="utf-8", errors="replace").strip()
    hint_block = "\nThe author says this is: {0}\n".format(hint) if hint else ""

    prompt = PROMPT_TEMPLATE.format(
        filename=path.name, code=code, hint_block=hint_block, lang=lang,
        comment_hint=comment_hint, platform_placeholder="<Platform>",
    )

    if dry_run:
        log("  (dry run) would call claude and file this solution")
        flush()
        return None

    log("  asking claude for an explanation...")
    raw = run_claude(prompt)
    data, header = parse_response(raw)

    if not data or not header:
        missing = "metadata" if not data else "header"
        log("  ! response was missing the {0}; leaving file in inbox".format(missing))
        if raw:
            FAILED.mkdir(parents=True, exist_ok=True)
            dump = FAILED / (path.stem + ".response.txt")
            dump.write_text(raw, encoding="utf-8")
            log("    raw reply saved to {0}".format(dump.relative_to(ROOT).as_posix()))
        flush()
        return None

    header = ensure_solved_tag(header, datetime.now().strftime("%Y-%m-%d"))

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
    parser.add_argument("--workers", type=int, default=3,
                        help="parallel Claude calls (default 3; 1 = serial)")
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
        log("Running {0} Claude calls in parallel.".format(workers))

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
