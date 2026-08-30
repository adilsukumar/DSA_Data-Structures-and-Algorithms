/*
 * Platform: LeetCode
 * Submission: 2039135929
 * Problem: Merge Sorted Array
 * Verdict: Compile Error
 * Date: 2026-06-20
 * URL: https://leetcode.com/problems/merge-sorted-array/
 *  */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; i++){
            nums1[m+1] = nums2[i];
        }
        sort(nums1);
    }
};