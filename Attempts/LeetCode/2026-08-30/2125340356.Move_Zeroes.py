"""
Platform: LeetCode
Submission: 2125340356
Problem: Move Zeroes
Verdict: Runtime Error
Date: 2026-08-30
URL: https://leetcode.com/problems/move-zeroes/
"""

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.sort(reverse=True)
        for i in range(len(nums)):
            while(nums[i] != 0){
                nums.sort()
            }        