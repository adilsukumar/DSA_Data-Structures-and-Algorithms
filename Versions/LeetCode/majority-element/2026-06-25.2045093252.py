"""
Platform: LeetCode
Submission: 2045093252
Problem: Majority Element
Verdict: Accepted
Submitted: 2026-06-25
Recorded in repository: 2026-09-24
Variant: Brute Force (inferred from submission order)
URL: https://leetcode.com/problems/majority-element/
"""

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        return nums[n//2]
        