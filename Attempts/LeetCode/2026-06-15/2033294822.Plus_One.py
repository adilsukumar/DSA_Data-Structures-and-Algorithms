"""
Platform: LeetCode
Submission: 2033294822
Problem: Plus One
Verdict: Wrong Answer
Date: 2026-06-15
URL: https://leetcode.com/problems/plus-one/
"""

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        a = digits[-1]
        if a < 9:
            b = a+1
            digits.remove(a)
            digits.append(b)
            return digits
        elif a == 9:
            digits.remove(a)
            digits.insert(0,-1)
            if a-1 == 9:
                digits.remove(a)
                digits.insert(0,a-1)
            else:
                digits.insert(0,1)
        