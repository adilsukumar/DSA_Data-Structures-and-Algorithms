"""
Platform: LeetCode
Submission: 2033302158
Problem: Plus One
Verdict: Runtime Error
Date: 2026-06-15
URL: https://leetcode.com/problems/plus-one/
"""

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits), -1, -1):
            if digits[i] == 9:
                digits[i] = 0
            else:
                digits += 1
                return digits
        return [1] + digits
        