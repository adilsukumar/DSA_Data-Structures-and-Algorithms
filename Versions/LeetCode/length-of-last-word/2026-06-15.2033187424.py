"""
Platform: LeetCode
Submission: 2033187424
Problem: Length of Last Word
Verdict: Accepted
Submitted: 2026-06-15
Recorded in repository: 2026-09-24
URL: https://leetcode.com/problems/length-of-last-word/
"""

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        a = s.split()
        b = list(a)
        c = b[-1]
        count = 0
        for i in c:
            count += 1
        return count
            
        