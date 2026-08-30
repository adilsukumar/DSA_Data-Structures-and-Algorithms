"""
Platform: LeetCode
Submission: 2026767279
Problem: Longest Common Prefix
Verdict: Runtime Error
Date: 2026-06-09
URL: https://leetcode.com/problems/longest-common-prefix/
"""

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans = ""
        for i in range(len(strs[0])):
            for j in range(1, len(strs)):
                if (strs[j][i] != strs[0][i]):
                    return ans
            ans += strs[0][i]
        return ans
            