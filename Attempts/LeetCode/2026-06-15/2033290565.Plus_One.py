"""
Platform: LeetCode
Submission: 2033290565
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
        d = a+1
        if d >= 10:
            c = split(d)
            digits.remove(b)
            return digits.append(c)
        else:
            return digits
        