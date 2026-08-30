"""
Platform: LeetCode
Submission: 2033289372
Problem: Plus One
Verdict: Wrong Answer
Date: 2026-06-15
URL: https://leetcode.com/problems/plus-one/
"""

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        a = digits[-1]
        digits.remove(a)
        digits.append(a+1)
        return digits
        