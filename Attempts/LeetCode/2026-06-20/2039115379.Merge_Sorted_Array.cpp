/*
 * Platform: LeetCode
 * Submission: 2039115379
 * Problem: Merge Sorted Array
 * Verdict: Compile Error
 * Date: 2026-06-20
 * URL: https://leetcode.com/problems/merge-sorted-array/
 *  */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m = nums1.size() - 1;
        n = nums2.size() - 1;
        nums1 = nums1 + nums2;
        nums1 = nums1.sort()
        return nums1;
    }
};