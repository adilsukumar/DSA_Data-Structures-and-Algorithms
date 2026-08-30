"""
Platform: LeetCode
Submission: 2083860959
Problem: Contains Duplicate
Verdict: Wrong Answer
Date: 2026-07-28
URL: https://leetcode.com/problems/contains-duplicate/
"""

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        a = set(nums)
        b = list(a)
        if b == nums:
            return True
        else:
            return False
        