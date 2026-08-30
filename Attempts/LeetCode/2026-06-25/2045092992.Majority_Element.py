"""
Platform: LeetCode
Submission: 2045092992
Problem: Majority Element
Verdict: Runtime Error
Date: 2026-06-25
URL: https://leetcode.com/problems/majority-element/
"""

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        return nums[n/2]
        