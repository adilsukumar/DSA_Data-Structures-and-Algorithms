#!/usr/bin/env python3
import sys
import json
import struct
import os
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

def read_message():
    text_length_bytes = sys.stdin.buffer.read(4)
    if len(text_length_bytes) == 0:
        sys.exit(0)
    text_length = struct.unpack('@I', text_length_bytes)[0]
    text = sys.stdin.buffer.read(text_length).decode('utf-8')
    return json.loads(text)

def send_message(message):
    encoded_content = json.dumps(message).encode('utf-8')
    sys.stdout.buffer.write(struct.pack('@I', len(encoded_content)))
    sys.stdout.buffer.write(encoded_content)
    sys.stdout.buffer.flush()

def main():
    try:
        message = read_message()
        session = str(message.get("leetcodeSession") or "").strip()
        if not session:
            send_message({"ok": False, "error": "LeetCode session missing"})
            return

        env = dict(os.environ, LEETCODE_SESSION=session, PYTHONIOENCODING="utf-8")
        command = [sys.executable, str(ROOT / "scripts" / "daily_sync.py")]
        if message.get("action") == "fullSync":
            command.append("--full-history")
        proc = subprocess.run(
            command,
            cwd=str(ROOT), env=env, capture_output=True, text=True,
            encoding="utf-8", errors="replace", timeout=3600,
        )
        tail = " ".join((proc.stdout or "").strip().splitlines()[-4:])[-1200:]
        
        send_message({
            "ok": proc.returncode == 0,
            "summary": tail,
            "error": "" if proc.returncode == 0 else tail or "Sync failed."
        })

    except Exception as exc:
        send_message({"ok": False, "error": str(exc)})

if __name__ == "__main__":
    main()
