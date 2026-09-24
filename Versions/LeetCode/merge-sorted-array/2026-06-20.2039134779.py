"""
Platform: LeetCode
Submission: 2039134779
Problem: Merge Sorted Array
Verdict: Accepted
Submitted: 2026-06-20
Recorded in repository: 2026-09-24
Variant: Improved Approach 1 (inferred from submission order)
URL: https://leetcode.com/problems/merge-sorted-array/
"""

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        new_list = nums1[0:m] + nums2[0:n] 
        nums1[:] = new_list
        nums1.sort()
