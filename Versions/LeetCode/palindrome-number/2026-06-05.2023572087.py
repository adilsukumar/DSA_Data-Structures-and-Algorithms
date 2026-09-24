"""
Platform: LeetCode
Submission: 2023572087
Problem: Palindrome Number
Verdict: Accepted
Submitted: 2026-06-05
Recorded in repository: 2026-09-24
Variant: Brute Force (inferred from submission order)
URL: https://leetcode.com/problems/palindrome-number/
"""

class Solution:
    def isPalindrome(self, x: int) -> bool:
        a = str(x)
        if (a[::-1] == a):
            return True
        else:
            return False
        