"""
Platform: CodeChef
Submission: 1295319672
Problem: FLOW007
Verdict: wrong answer
Date: 2026-06-25
URL: https://www.codechef.com/problems/FLOW007
"""

# cook your dish here
T = int(input())
N = int(input())

ans = 0

while N > 0:
    r = N % 10
    N = N // 10
    ans = N

print(ans)