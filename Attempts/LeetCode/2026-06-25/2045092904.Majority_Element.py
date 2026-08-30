"""
Platform: LeetCode
Submission: 2045092904
Problem: Majority Element
Verdict: Wrong Answer
Date: 2026-06-25
URL: https://leetcode.com/problems/majority-element/
"""

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        return nums[round(n/2)]
        