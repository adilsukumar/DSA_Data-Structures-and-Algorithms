"""
Platform: LeetCode
Submission: 2033308798
Problem: Plus One
Verdict: Accepted
Submitted: 2026-06-15
Recorded in repository: 2026-09-24
URL: https://leetcode.com/problems/plus-one/
"""

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits)-1, -1, -1):
            if digits[i] == 9:
                digits[i] = 0
            else:
                digits[i] += 1
                return digits
        return [1] + digits
        