"""
Platform: CodeChef
Submission: 1288093954
Problem: SNDMAX
Verdict: Accepted
Submitted: 2026-06-10
Recorded in repository: 2026-09-24
Variant: Optimized (inferred from submission order)
URL: https://www.codechef.com/problems/SNDMAX
"""

# cook your dish here

N = int(input())

for i in range(N):

    a, b, c = map(int, input().split())

    d = [a,b,c]

    d.sort()

    print(d[1])