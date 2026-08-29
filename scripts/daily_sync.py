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


def run(label, *args):
    print("\n=== {0} ===".format(label), flush=True)
    result = subprocess.run(
        [PYTHON, *args],
        cwd=str(ROOT),
        env=dict(os.environ, PYTHONIOENCODING="utf-8"),
        text=True,
    )
    if result.returncode:
        print("! {0} exited {1}; continuing with the remaining stages.".format(
            label, result.returncode), flush=True)
    return result.returncode


def main():
    print("DSA daily sync started {0}".format(datetime.now().isoformat(timespec="seconds")))

    # LeetCode reads LEETCODE_SESSION from the gitignored .env. If it expires,
    # this stage reports the error and the rest of the sync still runs.
    run("Import LeetCode", "scripts/import_leetcode.py")

    # CodeChef's public history/code APIs require no login cookie.
    run("Import CodeChef", "scripts/import_codechef.py", "--user", "adilsukumar")

    # This is the only stage that commits and pushes. Failed explanations stay
    # in inbox/ and are retried by the next nightly run.
    process_rc = run("Explain, file, index and push", "scripts/process_inbox.py", "--workers", "2")

    print("\nDSA daily sync finished {0}".format(datetime.now().isoformat(timespec="seconds")))
    return process_rc


if __name__ == "__main__":
    raise SystemExit(main())
