"""
Platform: LeetCode
Submission: 2033297500
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
            digits.pop(-1)
            digits.append(b)
            return digits
        elif a == 9:
            digits.pop(-1)
            digits.insert(0,0)
            return digits
            for i in digits:
                if digits[i] == 9:
                    digits.pop(i)
                    digits.append(1)
                    return digits
        