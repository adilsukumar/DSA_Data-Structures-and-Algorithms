"""
Platform: LeetCode
Submission: 2033186547
Problem: Length of Last Word
Verdict: Wrong Answer
Date: 2026-06-15
URL: https://leetcode.com/problems/length-of-last-word/
"""

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        a = s.split()
        b = list(a)
        return b[-1]
        