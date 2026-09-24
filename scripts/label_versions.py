#!/usr/bin/env python3
"""Label multiple submitted implementations using their chronological order."""

import argparse
import re
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parent.parent
VERSIONS = ROOT / "Versions"
VARIANT_RE = re.compile(r"(?m)^(?P<prefix>\s*(?:\*|#)?\s*)Variant:.*\r?\n")
RECORDED_RE = re.compile(
    r"(?m)^(?P<line>\s*(?:\*|#)?\s*Recorded in repository:.*\r?\n)")


def submission_number(path):
    numbers = [int(part) for part in path.name.split(".") if part.isdigit()]
    return max(numbers) if numbers else 0


def set_variant(path, label, from_head=False):
    if from_head:
        relative = path.relative_to(ROOT).as_posix()
        result = subprocess.run(
            ["git", "show", "HEAD:" + relative], cwd=str(ROOT),
            capture_output=True, check=False,
        )
        text = (result.stdout.decode("utf-8", errors="replace")
                if result.returncode == 0
                else path.read_text(encoding="utf-8", errors="replace"))
    else:
        text = path.read_text(encoding="utf-8", errors="replace")
    text = VARIANT_RE.sub("", text)
    if label:
        match = RECORDED_RE.search(text)
        if match:
            prefix_match = re.match(r"\s*(?:\*|#)?\s*", match.group("line"))
            prefix = prefix_match.group(0) if prefix_match else ""
            insertion = match.group("line") + prefix + "Variant: " + label + "\n"
            text = text[:match.start()] + insertion + text[match.end():]
    current = path.read_text(encoding="utf-8", errors="replace")
    if text != current:
        with path.open("w", encoding="utf-8", newline="") as stream:
            stream.write(text)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--from-head", action="store_true",
                        help="rebuild labels from committed file contents")
    args = parser.parse_args()
    labelled = 0
    for problem_dir in VERSIONS.glob("*/*"):
        if not problem_dir.is_dir():
            continue
        files = sorted(
            (path for path in problem_dir.iterdir() if path.is_file()),
            key=submission_number,
        )
        count = len(files)
        for index, path in enumerate(files):
            label = ""
            if count >= 2:
                if index == 0:
                    label = "Brute Force (inferred from submission order)"
                elif index == count - 1:
                    label = "Optimized (inferred from submission order)"
                else:
                    label = "Improved Approach {0} (inferred from submission order)".format(index)
            set_variant(path, label, from_head=args.from_head)
            labelled += bool(label)
    print("Labelled {0} submitted implementation version(s).".format(labelled))


if __name__ == "__main__":
    main()
