"""
Platform: LeetCode
Submission: 2039132786
Problem: Merge Sorted Array
Verdict: Wrong Answer
Date: 2026-06-20
URL: https://leetcode.com/problems/merge-sorted-array/
"""

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        new_list = nums1[0:m] + nums2[0:n] 
        nums1[:] = new_list
        return nums1