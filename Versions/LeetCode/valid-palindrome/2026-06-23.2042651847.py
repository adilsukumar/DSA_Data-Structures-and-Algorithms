"""
Platform: LeetCode
Submission: 2042651847
Problem: Valid Palindrome
Verdict: Accepted
Submitted: 2026-06-23
Recorded in repository: 2026-09-24
Variant: Brute Force (inferred from submission order)
URL: https://leetcode.com/problems/valid-palindrome/
"""

class Solution:
    def isPalindrome(self, s: str) -> bool:
        q = ""
        for i in s:
            if i.isalnum() == True or s == " ":
                q += i
                q = q.lower()
        if q[::] != q[::-1]:
            return False
        return True
                        
            