"""
Platform: LeetCode
Submission: 2045091604
Problem: Majority Element
Verdict: Runtime Error
Date: 2026-06-25
URL: https://leetcode.com/problems/majority-element/
"""

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = 0
        for i in nums:
            n += i
        a = nums.sort()
        return a[n/2]
        