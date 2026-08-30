"""
Platform: LeetCode
Submission: 2125331922
Problem: Move Zeroes
Verdict: Wrong Answer
Date: 2026-08-30
URL: https://leetcode.com/problems/move-zeroes/
"""

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.sort(reverse=True)
        