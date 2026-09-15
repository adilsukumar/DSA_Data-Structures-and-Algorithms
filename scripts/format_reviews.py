import os
import re
import textwrap
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

def main():
    folders_to_scan = [ROOT / "LeetCode", ROOT / "CodeChef"]
    for folder in folders_to_scan:
        if not folder.exists():
            continue
        for p in folder.rglob("*"):
            if not p.is_file() or p.suffix.lower() not in {".cpp", ".cc", ".py", ".java", ".js", ".ts", ".c", ".go", ".rs", ".kt"}:
                continue
            
            content = p.read_text(encoding="utf-8")
            
            # Find the Approach block
            if p.suffix == ".py":
                approach_match = re.search(r"Approach\n(.*?)\n\nComplexity", content, re.DOTALL)
                complexity_match = re.search(r"Complexity\n(.*?)\n\"\"\"", content, re.DOTALL)
            else:
                approach_match = re.search(r"Approach\n \*(.*?)\n \*\n \* Complexity", content, re.DOTALL)
                complexity_match = re.search(r"Complexity\n \*(.*?)\n \*/", content, re.DOTALL)
                
            if approach_match and complexity_match:
                # Clean up the prefixing
                raw_approach = approach_match.group(1)
                raw_complexity = complexity_match.group(1)
                
                # Strip out the " *" and newlines to get a single string
                clean_approach = re.sub(r"\n \*\s*", " ", raw_approach).strip()
                if clean_approach.startswith("* "):
                    clean_approach = clean_approach[2:].strip()
                clean_complexity = re.sub(r"\n \*\s*", " ", raw_complexity).strip()
                if clean_complexity.startswith("* "):
                    clean_complexity = clean_complexity[2:].strip()
                
                # Wrap it to 80 chars
                wrapped_approach = "\n".join(textwrap.wrap(clean_approach, width=80))
                wrapped_complexity = "\n".join(textwrap.wrap(clean_complexity, width=80))
                
                if p.suffix == ".py":
                    pass # We won't bother implementing py as user only has cpp
                else:
                    wrapped_approach = " " + wrapped_approach.replace("\n", "\n * ")
                    wrapped_complexity = " " + wrapped_complexity.replace("\n", "\n * ")
                    
                    new_content = content[:approach_match.start(1)] + wrapped_approach + content[approach_match.end(1):complexity_match.start(1)] + wrapped_complexity + content[complexity_match.end(1):]
                    p.write_text(new_content, encoding="utf-8")
                    print(f"Re-wrapped {p.name}")

if __name__ == "__main__":
    main()
