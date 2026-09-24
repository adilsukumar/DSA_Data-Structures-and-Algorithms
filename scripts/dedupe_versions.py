#!/usr/bin/env python3
"""Remove byte-identical archived implementations, keeping the earliest one."""

from pathlib import Path


ROOT = Path(__file__).resolve().parent.parent


def source_body(path):
    text = path.read_text(encoding="utf-8", errors="replace")
    marker = '\"\"\"\n\n' if path.suffix == ".py" else "*/\n\n"
    return text.partition(marker)[2].replace("\r\n", "\n").replace("\r", "\n").strip()


def submission_id(path):
    for part in path.name.split("."):
        if part.isdigit() and len(part) > 6:
            return int(part)
    return 0


def main():
    removed = 0
    versions = ROOT / "Versions"
    for problem_dir in versions.glob("*/*"):
        if not problem_dir.is_dir():
            continue
        seen = set()
        for path in sorted(problem_dir.iterdir(), key=submission_id):
            if not path.is_file():
                continue
            body = source_body(path)
            if body in seen:
                path.unlink()
                removed += 1
            else:
                seen.add(body)
    print("Removed {0} byte-identical accepted resubmission(s).".format(removed))


if __name__ == "__main__":
    main()
