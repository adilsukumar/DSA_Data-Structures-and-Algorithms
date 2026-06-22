from pathlib import Path

ROOT = Path(".")

cpp_count = 0
py_count = 0

leetcode_count = 0
codechef_count = 0

for file in ROOT.rglob("*"):

    if file.suffix not in [".cpp", ".py"]:
        continue

    path = str(file)

    if file.suffix == ".cpp":
        cpp_count += 1

    if file.suffix == ".py":
        py_count += 1

    if "LeetCode" in path:
        leetcode_count += 1

    if "CodeChef" in path:
        codechef_count += 1

total = cpp_count + py_count

generated = f"""
## 📊 Live Statistics

| Metric | Count |
|---------|---------|
| 🚀 Total Problems | {total} |
| 🟧 LeetCode | {leetcode_count} |
| 🍫 CodeChef | {codechef_count} |
| 💙 C++ Solutions | {cpp_count} |
| 🐍 Python Solutions | {py_count} |

### Problems by Platform

```mermaid
pie title Problems by Platform
    "LeetCode" : {leetcode_count}
    "CodeChef" : {codechef_count}
```

### Languages Used

```mermaid
pie title Languages Used
    "C++" : {cpp_count}
    "Python" : {py_count}
```

### Goal Progress

```mermaid
xychart-beta
    title "Progress to 1000 Problems"
    x-axis ["Solved","Goal"]
    y-axis "Problems" 0 --> 1000
    bar [{total},1000]
```

"""

readme = Path("README.md")

content = readme.read_text(encoding="utf-8")

start = "<!-- STATS_START -->"
end = "<!-- STATS_END -->"

before = content.split(start)[0]
after = content.split(end)[1]

new_content = before + start + "\n" + generated + "\n" + end + after

readme.write_text(new_content, encoding="utf-8")
