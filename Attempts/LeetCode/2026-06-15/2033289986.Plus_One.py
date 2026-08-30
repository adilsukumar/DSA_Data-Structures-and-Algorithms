"""
Platform: LeetCode
Submission: 2033289986
Problem: Plus One
Verdict: Runtime Error
Date: 2026-06-15
URL: https://leetcode.com/problems/plus-one/
"""

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        a = digits[-1]
        digits.remove(a)
        b = digits.append(a+1)
        if b >= 10:
            c = split(b)
            return digits.append(c)
        else:
            return digits
        