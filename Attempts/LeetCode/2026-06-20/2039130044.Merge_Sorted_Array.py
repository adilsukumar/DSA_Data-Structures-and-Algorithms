"""
Platform: LeetCode
Submission: 2039130044
Problem: Merge Sorted Array
Verdict: Runtime Error
Date: 2026-06-20
URL: https://leetcode.com/problems/merge-sorted-array/
"""

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        for j in m:
            for i in nums1:
                nums1 = nums1+nums2

        nums1.sort()
        return nums1