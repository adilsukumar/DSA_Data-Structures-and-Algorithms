"""
Platform: LeetCode
Submission: 2039125999
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
        for i in nums2:
            if nums2[i] != 0:
                nums1.append(i)
                nums1.remove(0)
        nums1.sort()
        return nums1