"""
Platform: LeetCode
Submission: 2077538299
Problem: Find the Index of the First Occurrence in a String
Verdict: Accepted
Submitted: 2026-07-22
Recorded in repository: 2026-09-24
URL: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
"""

class Solution:
    def strStr(self, haystack, needle):

        n, m = len(haystack), len(needle)

        for i in range(n - m + 1):
            if haystack[i:i+m] == needle:
                return i

        return -1