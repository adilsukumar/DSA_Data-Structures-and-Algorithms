/*
 * Platform: LeetCode
 * Submission: 2045094736
 * Problem: Majority Element
 * Verdict: Accepted
 * Submitted: 2026-06-25
 * Recorded in repository: 2026-09-24
 * Variant: Improved Approach 1 (inferred from submission order)
 * URL: https://leetcode.com/problems/majority-element/
 *  */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() - 1;
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};