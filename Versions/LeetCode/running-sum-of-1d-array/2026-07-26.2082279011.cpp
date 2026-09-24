/*
 * Platform: LeetCode
 * Submission: 2082279011
 * Problem: Running Sum of 1d Array
 * Verdict: Accepted
 * Submitted: 2026-07-26
 * Recorded in repository: 2026-09-24
 * URL: https://leetcode.com/problems/running-sum-of-1d-array/
 *  */

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int N = nums.size();
        for(int i = 1; i < N; i++){
            nums[i] = nums[i] + nums[i-1];
        }
        return nums;
    }
};