"""
Platform: LeetCode
Submission: 2042644849
Problem: Valid Palindrome
Verdict: Runtime Error
Date: 2026-06-23
URL: https://leetcode.com/problems/valid-palindrome/
"""

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s.lower()
        s.delete()
        print(s)
        