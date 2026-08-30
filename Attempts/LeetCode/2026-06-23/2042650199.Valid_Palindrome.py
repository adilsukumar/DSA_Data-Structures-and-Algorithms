"""
Platform: LeetCode
Submission: 2042650199
Problem: Valid Palindrome
Verdict: Wrong Answer
Date: 2026-06-23
URL: https://leetcode.com/problems/valid-palindrome/
"""

class Solution:
    def isPalindrome(self, s: str) -> bool:
        q = ""
        for i in s:
            if s.isalnum() == True or s == " ":
                q.append()
                q.lower()
                if q[::] == q[::-1]:
                    return True
                else:
                    return False
        