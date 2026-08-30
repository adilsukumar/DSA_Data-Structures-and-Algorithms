"""
Platform: LeetCode
Submission: 2033288140
Problem: Plus One
Verdict: Wrong Answer
Date: 2026-06-15
URL: https://leetcode.com/problems/plus-one/
"""

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in digits:
            return digits[-1] + 1
        