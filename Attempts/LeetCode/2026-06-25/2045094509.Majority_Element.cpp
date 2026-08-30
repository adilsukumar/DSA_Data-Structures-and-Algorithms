/*
 * Platform: LeetCode
 * Submission: 2045094509
 * Problem: Majority Element
 * Verdict: Compile Error
 * Date: 2026-06-25
 * URL: https://leetcode.com/problems/majority-element/
 *  */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() - 1;
        nums.sorted(nums.begin(), nums.end());
        return nums[n/2];
    }
};