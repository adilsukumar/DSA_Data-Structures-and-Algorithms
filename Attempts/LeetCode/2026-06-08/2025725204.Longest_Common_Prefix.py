"""
Platform: LeetCode
Submission: 2025725204
Problem: Longest Common Prefix
Verdict: Wrong Answer
Date: 2026-06-08
URL: https://leetcode.com/problems/longest-common-prefix/
"""

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans = ""

        for i in range(len(strs[0])):

            for j in range(1, len(strs)):

                if strs[j][i] != strs[0][i]:
                    print(ans)
                    exit()

            ans += strs[0][i]

        print("{ans}")