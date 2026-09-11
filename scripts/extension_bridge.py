#!/usr/bin/env python3
"""Authenticated loopback bridge for the DSA Chrome extension."""

import json
import os
import subprocess
import sys
import threading
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TOKEN_FILE = ROOT / "extension" / "bridge.token"
ORIGIN = "chrome-extension://plbilacillelljfdjbkhhmkofghlfajl"
SYNC_LOCK = threading.Lock()


class Handler(BaseHTTPRequestHandler):
    def log_message(self, _format, *_args):
        return

    def send_json(self, status, value):
        data = json.dumps(value).encode("utf-8")
        self.send_response(status)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(data)))
        self.send_header("Access-Control-Allow-Origin", ORIGIN)
        self.end_headers()
        self.wfile.write(data)

    def authorized(self):
        try:
            expected = TOKEN_FILE.read_text(encoding="utf-8").strip()
        except OSError:
            return False
        return (
            self.headers.get("Origin") == ORIGIN
            and self.headers.get("X-DSA-Token", "") == expected
        )

    def do_OPTIONS(self):
        if self.headers.get("Origin") != ORIGIN:
            self.send_error(403)
            return
        self.send_response(204)
        self.send_header("Access-Control-Allow-Origin", ORIGIN)
        self.send_header("Access-Control-Allow-Headers", "Content-Type, X-DSA-Token")
        self.send_header("Access-Control-Allow-Methods", "POST, OPTIONS")
        self.end_headers()

    def do_GET(self):
        if self.path == "/health":
            self.send_json(200, {"ok": True})
        else:
            self.send_error(404)

    def do_POST(self):
        if self.path != "/sync":
            self.send_error(404)
            return
        if not self.authorized():
            self.send_json(403, {"ok": False, "error": "Extension bridge authorization failed."})
            return
        try:
            size = int(self.headers.get("Content-Length", "0"))
            if size <= 0 or size > 100_000:
                raise ValueError("invalid request size")
            message = json.loads(self.rfile.read(size).decode("utf-8"))
            session = str(message.get("leetcodeSession") or "").strip()
            if not session:
                raise ValueError("LeetCode session missing")
        except Exception as exc:
            self.send_json(400, {"ok": False, "error": str(exc)})
            return
        if not SYNC_LOCK.acquire(blocking=False):
            self.send_json(409, {"ok": False, "error": "A sync is already running."})
            return
        try:
            env = dict(os.environ, LEETCODE_SESSION=session, PYTHONIOENCODING="utf-8")
            proc = subprocess.run(
                [sys.executable, str(ROOT / "scripts" / "daily_sync.py")],
                cwd=str(ROOT), env=env, capture_output=True, text=True,
                encoding="utf-8", errors="replace", timeout=3600,
            )
            tail = " ".join((proc.stdout or "").strip().splitlines()[-4:])[-1200:]
            self.send_json(200 if proc.returncode == 0 else 500, {
                "ok": proc.returncode == 0,
                "summary": tail,
                "error": "" if proc.returncode == 0 else tail or "Sync failed."
            })
        except subprocess.TimeoutExpired:
            self.send_json(504, {"ok": False, "error": "Sync exceeded one hour."})
        finally:
            SYNC_LOCK.release()


if __name__ == "__main__":
    ThreadingHTTPServer(("127.0.0.1", 8765), Handler).serve_forever()
