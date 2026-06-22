import json
import urllib.parse
from pathlib import Path

ROOT = Path(".")

cpp_count = 0
py_count = 0

leetcode_count = 0
codechef_count = 0

# LeetCode stats
lc_easy = 0
lc_medium = 0
lc_hard = 0

# CodeChef stats
cc_500 = 0
cc_500_1000 = 0
cc_1000_1400 = 0
cc_1400_1600 = 0
cc_1600_1800 = 0
cc_1800_2000 = 0
cc_2000_2500 = 0

for file in ROOT.rglob("*"):
    if file.suffix not in [".cpp", ".py"]:
        continue

    path = str(file)
    path_lower = path.lower()
    
    # Exclude files that are not in LeetCode or CodeChef folders
    if "leetcode" not in path_lower and "codechef" not in path_lower:
        continue

    # Language
    if file.suffix == ".cpp":
        cpp_count += 1
    if file.suffix == ".py":
        py_count += 1

    # Platform & Difficulty
    if "leetcode" in path_lower:
        leetcode_count += 1
        if "easy" in path_lower:
            lc_easy += 1
        elif "medium" in path_lower:
            lc_medium += 1
        elif "hard" in path_lower:
            lc_hard += 1

    if "codechef" in path_lower:
        codechef_count += 1
        if "500_difficulty_rating" in path_lower:
            cc_500 += 1
        elif "500_to_1000" in path_lower:
            cc_500_1000 += 1
        elif "1000_to_1400" in path_lower:
            cc_1000_1400 += 1
        elif "1400_to_1600" in path_lower:
            cc_1400_1600 += 1
        elif "1600_to_1800" in path_lower:
            cc_1600_1800 += 1
        elif "1800_to_2000" in path_lower:
            cc_1800_2000 += 1
        elif "2000_to_2500" in path_lower:
            cc_2000_2500 += 1

total = cpp_count + py_count

# Milestone logic
milestone = ((total // 50) + 1) * 50
progress_percent = int((total / milestone) * 100) if milestone > 0 else 0

# --- Beautiful Charts generation using quickchart.io ---

def get_quickchart_url(chart_config, width=500, height=300):
    encoded = urllib.parse.quote(json.dumps(chart_config))
    return f"https://quickchart.io/chart?c={encoded}&w={width}&h={height}&bkg=transparent"

# 1. Platform Pie Chart
platforms_config = {
    "type": "doughnut",
    "data": {
        "labels": ["LeetCode", "CodeChef"],
        "datasets": [{"data": [leetcode_count, codechef_count], "backgroundColor": ["#FFA116", "#5B4638"]}]
    },
    "options": {
        "plugins": {
            "legend": {"position": "right", "labels": {"fontColor": "#ffffff", "fontSize": 14}}
        },
        "title": {"display": True, "text": "Platforms", "fontColor": "#ffffff", "fontSize": 18}
    }
}
platforms_url = get_quickchart_url(platforms_config)

# 2. Language Pie Chart
languages_config = {
    "type": "doughnut",
    "data": {
        "labels": ["C++", "Python"],
        "datasets": [{"data": [cpp_count, py_count], "backgroundColor": ["#00599C", "#3776AB"]}]
    },
    "options": {
        "plugins": {
            "legend": {"position": "right", "labels": {"fontColor": "#ffffff", "fontSize": 14}}
        },
        "title": {"display": True, "text": "Languages", "fontColor": "#ffffff", "fontSize": 18}
    }
}
languages_url = get_quickchart_url(languages_config)


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

| 🚀 Total Problems | 💙 C++ Solutions | 🐍 Python Solutions |
| :---: | :---: | :---: |
| **{total}** | **{cpp_count}** | **{py_count}** |

### 🏆 Milestone Progress: {total} / {milestone}

![Milestone Progress](https://quickchart.io/chart?c={{type:'progressBar',data:{{datasets:[{{data:[{progress_percent}],backgroundColor:'green'}}]}}}}&w=800&h=50)

> 🎉 Only **{milestone - total}** problems left to reach the next big milestone of {milestone}!

---

<div align="center">
  <img src="{platforms_url}" alt="Platforms Chart" />
  <img src="{languages_url}" alt="Languages Chart" />
</div>

---

### 🟧 LeetCode Breakdown

| Difficulty | Count |
| :--- | :---: |
| 🟢 Easy | {lc_easy} |
| 🟡 Medium | {lc_medium} |
| 🔴 Hard | {lc_hard} |

### 🍫 CodeChef Breakdown

| Difficulty Rating | Count |
| :--- | :---: |
| 🔹 500 Rating | {cc_500} |
| 🔹 500 to 1000 | {cc_500_1000} |
| 🔹 1000 to 1400 | {cc_1000_1400} |
| 🔹 1400 to 1600 | {cc_1400_1600} |
| 🔹 1600 to 1800 | {cc_1600_1800} |
| 🔹 1800 to 2000 | {cc_1800_2000} |
| 🔹 2000 to 2500 | {cc_2000_2500} |
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
