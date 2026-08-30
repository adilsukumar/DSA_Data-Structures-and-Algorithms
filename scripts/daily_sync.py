#!/usr/bin/env python3
"""Nightly end-to-end sync for LeetCode and CodeChef.

The importers are intentionally independent: one platform being unavailable
must not prevent the other platform, or already queued inbox files, from being
processed. Raw files remain gitignored in inbox/ until process_inbox.py has
successfully documented and filed them.
"""

import os
import subprocess
import sys
from datetime import datetime
from pathlib import Path


ROOT = Path(__file__).resolve().parent.parent
PYTHON = sys.executable
STATUS_DIR = ROOT / "sync_status"
LOG_FILE = STATUS_DIR / "daily_sync.log"
LEETCODE_ALERT = STATUS_DIR / "LEETCODE_LOGIN_REQUIRED.txt"


def run(label, *args):
    heading = "\n=== {0} ===\n".format(label)
    print(heading, end="", flush=True)
    with LOG_FILE.open("a", encoding="utf-8") as log:
        log.write(heading)
    process = subprocess.Popen(
        [PYTHON, *args],
        cwd=str(ROOT),
        env=dict(os.environ, PYTHONIOENCODING="utf-8"),
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
        encoding="utf-8",
        errors="replace",
    )
    output = []
    with LOG_FILE.open("a", encoding="utf-8") as log:
        for line in process.stdout:
            print(line, end="", flush=True)
            log.write(line)
            log.flush()
            output.append(line)
    returncode = process.wait()
    if returncode:
        print("! {0} exited {1}; continuing with the remaining stages.".format(
            label, returncode), flush=True)
    return returncode, "".join(output)


def update_leetcode_status(returncode, output):
    auth_problem = returncode and any(phrase in output.lower() for phrase in (
        "leetcode_session", "invalid or expired", "missing, wrong or expired",
    ))
    if auth_problem:
        message = (
            "LeetCode login refresh required.\n\n"
            "The nightly sync could not authenticate. Log in to LeetCode, copy "
            "the new LEETCODE_SESSION cookie, and replace its value in:\n"
            "{0}\.env\n\nDetected: {1}\n"
        ).format(ROOT, datetime.now().isoformat(timespec="seconds"))
        LEETCODE_ALERT.write_text(message, encoding="utf-8")
        # The task runs in the interactive user session, so msg.exe normally
        # produces a visible Windows dialog. The status file is the fallback.
        try:
            subprocess.run(
                ["msg.exe", os.environ.get("USERNAME", "*"),
                 "LeetCode login expired. Refresh LEETCODE_SESSION in the DSA repo .env file."],
                timeout=15, check=False, capture_output=True,
            )
        except Exception:
            pass
    elif returncode == 0 and LEETCODE_ALERT.exists():
        LEETCODE_ALERT.unlink()


def commit_attempts():
    """Commit only the archived attempts and their README counter."""
    attempts = ROOT / "Attempts"
    if not attempts.exists():
        return 0
    subprocess.run([PYTHON, "scripts/update_stats.py"], cwd=str(ROOT), check=True)
    subprocess.run(["git", "add", "--", "Attempts", "README.md"],
                   cwd=str(ROOT), check=True)
    staged = subprocess.run(["git", "diff", "--staged", "--quiet"], cwd=str(ROOT))
    if staged.returncode == 0:
        print("No new attempts to commit.")
        return 0
    day = datetime.now().strftime("%d %b %Y")
    subprocess.run(["git", "commit", "-m", "attempts: " + day],
                   cwd=str(ROOT), check=True)
    pushed = subprocess.run(["git", "push"], cwd=str(ROOT))
    return pushed.returncode


def main():
    STATUS_DIR.mkdir(exist_ok=True)
    print("DSA daily sync started {0}".format(datetime.now().isoformat(timespec="seconds")))

    # LeetCode reads LEETCODE_SESSION from the gitignored .env. If it expires,
    # this stage reports the error and the rest of the sync still runs.
    leetcode_rc, leetcode_output = run("Import LeetCode", "scripts/import_leetcode.py")
    update_leetcode_status(leetcode_rc, leetcode_output)

    # CodeChef's public history/code APIs require no login cookie.
    run("Import CodeChef", "scripts/import_codechef.py", "--user", "adilsukumar")

    # This is the only stage that commits and pushes. Failed explanations stay
    # in inbox/ and are retried by the next nightly run.
    process_rc, _ = run("File, index and push", "scripts/process_inbox.py", "--workers", "2")
    attempts_rc = commit_attempts()

    print("\nDSA daily sync finished {0}".format(datetime.now().isoformat(timespec="seconds")))
    return process_rc if process_rc not in (0, 1) else attempts_rc


if __name__ == "__main__":
    raise SystemExit(main())
