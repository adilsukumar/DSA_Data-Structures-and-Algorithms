import json
import urllib.parse
from pathlib import Path

ROOT = Path(".")

cpp_count = 0
py_count = 0

leetcode_count = 0
codechef_count = 0

easy_count = 0
medium_count = 0
hard_count = 0

for file in ROOT.rglob("*"):
    if file.suffix not in [".cpp", ".py"]:
        continue

    path = str(file)

    # Language
    if file.suffix == ".cpp":
        cpp_count += 1
    if file.suffix == ".py":
        py_count += 1

    # Platform & Difficulty
    path_lower = path.lower()
    if "leetcode" in path_lower:
        leetcode_count += 1
        if "easy" in path_lower:
            easy_count += 1
        elif "medium" in path_lower:
            medium_count += 1
        elif "hard" in path_lower:
            hard_count += 1

    if "codechef" in path_lower:
        codechef_count += 1
        if "500_difficulty_rating" in path_lower:
            easy_count += 1
        elif "500_to_1000" in path_lower:
            medium_count += 1
        else:
            hard_count += 1

total = cpp_count + py_count

# Milestone logic
milestone = ((total // 50) + 1) * 50
progress_percent = int((total / milestone) * 100) if milestone > 0 else 0

# --- Beautiful Charts generation using quickchart.io ---

def get_quickchart_url(chart_config):
    encoded = urllib.parse.quote(json.dumps(chart_config))
    return f"https://quickchart.io/chart?c={encoded}&bkg=white"

# 1. Platform Pie Chart
platforms_config = {
    "type": "doughnut",
    "data": {
        "labels": ["LeetCode", "CodeChef"],
        "datasets": [{"data": [leetcode_count, codechef_count], "backgroundColor": ["#FFA116", "#5B4638"]}]
    },
    "options": {"plugins": {"legend": {"position": "bottom"}}, "title": {"display": True, "text": "Platforms"}}
}
platforms_url = get_quickchart_url(platforms_config)

# 2. Language Pie Chart
languages_config = {
    "type": "doughnut",
    "data": {
        "labels": ["C++", "Python"],
        "datasets": [{"data": [cpp_count, py_count], "backgroundColor": ["#00599C", "#3776AB"]}]
    },
    "options": {"plugins": {"legend": {"position": "bottom"}}, "title": {"display": True, "text": "Languages"}}
}
languages_url = get_quickchart_url(languages_config)

# 3. Difficulty Bar Chart
difficulty_config = {
    "type": "bar",
    "data": {
        "labels": ["Easy", "Medium", "Hard"],
        "datasets": [{
            "label": "Problems Solved",
            "data": [easy_count, medium_count, hard_count],
            "backgroundColor": ["#00b8a3", "#ffc01e", "#ff375f"]
        }]
    },
    "options": {
        "plugins": {"legend": {"display": False}},
        "title": {"display": True, "text": "Difficulty"},
        "scales": {"y": {"beginAtZero": True, "ticks": {"stepSize": 1}}}
    }
}
difficulty_url = get_quickchart_url(difficulty_config)


# --- Update BADGES ---

badges_str = f"""
<!-- BADGES_START -->
<a href="https://github.com/adilsukumar/DSA_Data-Structures-and-Algorithms"><img src="https://img.shields.io/badge/Problems%20Solved-{total}-blueviolet?style=for-the-badge&logo=codeforces" /></a>
<a href="https://leetcode.com"><img src="https://img.shields.io/badge/LeetCode-{leetcode_count}-FFA116?style=for-the-badge&logo=leetcode" /></a>
<a href="https://codechef.com"><img src="https://img.shields.io/badge/CodeChef-{codechef_count}-5B4638?style=for-the-badge&logo=codechef" /></a>
<a href="#"><img src="https://img.shields.io/badge/Milestone_{milestone}-{progress_percent}%25-success?style=for-the-badge" /></a>
<a href="#"><img src="https://img.shields.io/badge/Goal-{total}%2F1000-orange?style=for-the-badge" /></a>
<!-- BADGES_END -->
"""

# --- Update STATS ---

generated = f"""
## 📊 Live Statistics & Insights

| Metric | Count |
|---------|---------|
| 🚀 Total Problems | **{total}** |
| 🟧 LeetCode | {leetcode_count} |
| 🍫 CodeChef | {codechef_count} |
| 💙 C++ Solutions | {cpp_count} |
| 🐍 Python Solutions | {py_count} |
| 🟢 Easy | {easy_count} |
| 🟡 Medium | {medium_count} |
| 🔴 Hard | {hard_count} |

### 🏆 Milestone Progress: {total} / {milestone}

![Milestone Progress](https://quickchart.io/chart?c={{type:'progressBar',data:{{datasets:[{{data:[{progress_percent}],backgroundColor:'green'}}]}}}}&w=600&h=50)

> 🎉 Only **{milestone - total}** problems left to reach the next big milestone of {milestone}!

### 📈 Breakdown

<div align="center">
  <img src="{platforms_url}" width="30%" alt="Platforms Chart" />
  <img src="{languages_url}" width="30%" alt="Languages Chart" />
  <img src="{difficulty_url}" width="30%" alt="Difficulty Chart" />
</div>
"""

readme = Path("README.md")
content = readme.read_text(encoding="utf-8")

# Replace badges
badges_start = "<!-- BADGES_START -->"
badges_end = "<!-- BADGES_END -->"
b_before = content.split(badges_start)[0]
b_after = content.split(badges_end)[1]
content = b_before + badges_str.strip() + "\n" + b_after

# Replace stats
stats_start = "<!-- STATS_START -->"
stats_end = "<!-- STATS_END -->"
s_before = content.split(stats_start)[0]
s_after = content.split(stats_end)[1]
content = s_before + stats_start + "\n" + generated + "\n" + stats_end + s_after

readme.write_text(content, encoding="utf-8")
