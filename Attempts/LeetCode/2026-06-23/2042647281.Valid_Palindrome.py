"""
Platform: LeetCode
Submission: 2042647281
Problem: Valid Palindrome
Verdict: Runtime Error
Date: 2026-06-23
URL: https://leetcode.com/problems/valid-palindrome/
"""

class Solution:
    def isPalindrome(self, s: str) -> bool:
        q = ""
        for i in s:
            if i == s.isalpha():
                q.append()
                q.lower()
                for j in s:
                    for k in s:
                        if q[j] == q[k]:
                            k -= k
                            j += j
                        
                return true
            elif s == " ":
                return true
            else:
                return false
        