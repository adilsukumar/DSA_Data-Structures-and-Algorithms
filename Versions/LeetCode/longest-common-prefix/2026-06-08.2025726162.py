"""
Platform: LeetCode
Submission: 2025726162
Problem: Longest Common Prefix
Verdict: Accepted
Submitted: 2026-06-08
Recorded in repository: 2026-09-24
Variant: Brute Force (inferred from submission order)
URL: https://leetcode.com/problems/longest-common-prefix/
"""

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans = ""

        for i in range(len(strs[0])):

            for j in range(1, len(strs)):

                if i >= len(strs[j]) or strs[j][i] != strs[0][i]:
                    return ans

            ans += strs[0][i]

        return ans
        