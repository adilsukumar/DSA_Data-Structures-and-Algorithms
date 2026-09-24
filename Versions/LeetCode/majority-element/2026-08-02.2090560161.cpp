/*
 * Platform: LeetCode
 * Submission: 2090560161
 * Problem: Majority Element
 * Verdict: Accepted
 * Submitted: 2026-08-02
 * Recorded in repository: 2026-09-24
 * Variant: Optimized (inferred from submission order)
 * URL: https://leetcode.com/problems/majority-element/
 *  */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int half = nums.size()/2;
        return nums[half];
    }
};