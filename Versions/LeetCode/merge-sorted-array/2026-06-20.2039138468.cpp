/*
 * Platform: LeetCode
 * Submission: 2039138468
 * Problem: Merge Sorted Array
 * Verdict: Accepted
 * Submitted: 2026-06-20
 * Recorded in repository: 2026-09-24
 * Variant: Optimized (inferred from submission order)
 * URL: https://leetcode.com/problems/merge-sorted-array/
 *  */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        for(int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }
};