"""
Platform: LeetCode
Submission: 2033187132
Problem: Length of Last Word
Verdict: Runtime Error
Date: 2026-06-15
URL: https://leetcode.com/problems/length-of-last-word/
"""

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        a = s.split()
        b = list(a)
        c = b[-1]
        count = 0
        for i in range(c):
            count += 1
            return count
            
        