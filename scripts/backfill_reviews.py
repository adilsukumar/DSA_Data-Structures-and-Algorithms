#!/usr/bin/env python3
"""
backfill_reviews.py -- fill in AI explanations for old solutions.

This script scans the repository for solutions that still have the
"Pending manual review" placeholder. It runs the AI review (via Groq/Ollama)
and updates the file headers.
"""

import os
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from scripts.process_inbox import get_ai_review

def main():
    folders_to_scan = [ROOT / "LeetCode", ROOT / "CodeChef"]
    files_to_update = []
    
    for folder in folders_to_scan:
        if not folder.exists():
            continue
        for p in folder.rglob("*"):
            if not p.is_file() or p.suffix.lower() not in {".cpp", ".cc", ".py", ".java", ".js", ".ts", ".c", ".go", ".rs", ".kt"}:
                continue
            content = p.read_text(encoding="utf-8")
            if "Pending manual review" in content:
                files_to_update.append(p)
                
    if not files_to_update:
        print("No files found with 'Pending manual review'.")
        return

    print(f"Found {len(files_to_update)} files needing AI review.")
    
    for idx, path in enumerate(files_to_update, 1):
        print(f"[{idx}/{len(files_to_update)}] Processing {path.name}...")
        content = path.read_text(encoding="utf-8")
        
        # Extract title from the file
        title_match = re.search(r"@title\s+(.+)", content)
        title = title_match.group(1).strip() if title_match else path.stem
        
        # Extract the pure code by finding the end of the header comment
        if content.startswith("/*"):
            parts = content.split("*/\n", 1)
        elif content.startswith("\"\"\""):
            parts = content.split("\"\"\"\n", 2)
            if len(parts) > 2: # First """ starts it, second """ ends it
                parts = ["\"\"\"" + parts[1] + "\"\"\"", parts[2]]
        else:
            parts = ["", content]
            
        code = parts[-1].strip() if len(parts) > 1 else content
        
        # Generate the review
        review = get_ai_review(code, title)
        
        if review.get("pattern") == "Pending manual review":
            print("  ! API failed or Ollama not running. Skipping the rest.")
            break
            
        # Replace the placeholders in the content
        new_content = re.sub(r"@pattern\s+Pending manual review", f"@pattern    {review.get('pattern', 'Unclassified').replace(chr(10), ' ')}", content)
        
        # Fix the Approach and Complexity blocks. They span lines.
        # We replace the text under "Approach" and "Complexity"
        
        if path.suffix == ".py":
            # Python headers
            approach_re = r"Approach\nPending manual review\. The submitted code is preserved exactly below\."
            complexity_re = r"Complexity\nPending manual review\."
            new_content = re.sub(approach_re, f"Approach\n{review.get('approach', '')}", new_content)
            new_content = re.sub(complexity_re, f"Complexity\n{review.get('complexity', '')}", new_content)
        else:
            # C-style headers
            approach_re = r"Approach\n \* Pending manual review\. The submitted code is preserved exactly below\."
            complexity_re = r"Complexity\n \* Pending manual review\."
            # Multiline approach requires prefixing newlines with " * "
            approach_formatted = review.get("approach", "").replace("\n", "\n * ")
            complexity_formatted = review.get("complexity", "").replace("\n", "\n * ")
            new_content = re.sub(approach_re, f"Approach\n * {approach_formatted}", new_content)
            new_content = re.sub(complexity_re, f"Complexity\n * {complexity_formatted}", new_content)
            
        path.write_text(new_content, encoding="utf-8")
        print("  âœ“ Updated.")

if __name__ == "__main__":
    main()
