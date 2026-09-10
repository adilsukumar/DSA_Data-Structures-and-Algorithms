#!/usr/bin/env python3
"""Chrome native-messaging bridge for the model-free DSA sync."""

import json
import os
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def read_message():
    raw = sys.stdin.buffer.read(4)
    if len(raw) != 4:
        return None
    size = struct.unpack("<I", raw)[0]
    return json.loads(sys.stdin.buffer.read(size).decode("utf-8"))


def send_message(value):
    data = json.dumps(value).encode("utf-8")
    sys.stdout.buffer.write(struct.pack("<I", len(data)))
    sys.stdout.buffer.write(data)
    sys.stdout.buffer.flush()


def main():
    message = read_message() or {}
    if message.get("action") != "sync":
        send_message({"ok": False, "error": "Unknown action."})
        return 1
    token = str(message.get("leetcodeSession") or "").strip()
    if not token:
        send_message({"ok": False, "error": "LeetCode browser session not found."})
        return 1
    env = dict(os.environ, LEETCODE_SESSION=token, PYTHONIOENCODING="utf-8")
    proc = subprocess.run(
        [sys.executable, str(ROOT / "scripts" / "daily_sync.py")],
        cwd=str(ROOT), env=env, capture_output=True, text=True,
        encoding="utf-8", errors="replace", timeout=3600,
    )
    tail = " ".join((proc.stdout or "").strip().splitlines()[-3:])[-800:]
    send_message({"ok": proc.returncode == 0, "summary": tail,
                  "error": "" if proc.returncode == 0 else tail or "Sync exited with an error."})
    return proc.returncode


if __name__ == "__main__":
    raise SystemExit(main())
