/*
 * Platform: LeetCode
 * Submission: 2090559711
 * Problem: Majority Element
 * Verdict: Compile Error
 * Date: 2026-08-02
 * URL: https://leetcode.com/problems/majority-element/
 *  */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        nums.sort(nums.begin(), nums.end());
        int half = nums/2;
        return nums[half];
    }
};