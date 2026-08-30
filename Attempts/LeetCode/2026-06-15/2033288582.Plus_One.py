"""
Platform: LeetCode
Submission: 2033288582
Problem: Plus One
Verdict: Runtime Error
Date: 2026-06-15
URL: https://leetcode.com/problems/plus-one/
"""

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in digits:
            digits.remove([-1])
            digits.append([-1] + 1)
            return digits
        