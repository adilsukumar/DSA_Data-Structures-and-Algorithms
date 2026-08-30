"""
Platform: LeetCode
Submission: 2083860656
Problem: Contains Duplicate
Verdict: Wrong Answer
Date: 2026-07-28
URL: https://leetcode.com/problems/contains-duplicate/
"""

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        a = set(nums)
        if a == nums:
            return True
        else:
            return False
        