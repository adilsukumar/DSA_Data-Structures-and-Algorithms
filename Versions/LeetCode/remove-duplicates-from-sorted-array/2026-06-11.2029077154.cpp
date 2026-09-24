/*
 * Platform: LeetCode
 * Submission: 2029077154
 * Problem: Remove Duplicates from Sorted Array
 * Verdict: Accepted
 * Submitted: 2026-06-11
 * Recorded in repository: 2026-09-24
 * URL: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *  */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto snehal = std::unique(nums.begin(), nums.end());
        return snehal - nums.begin();
    }
};