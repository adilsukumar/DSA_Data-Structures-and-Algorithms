/*
 * Platform: LeetCode
 * Submission: 2082273086
 * Problem: Running Sum of 1d Array
 * Verdict: Compile Error
 * Date: 2026-07-26
 * URL: https://leetcode.com/problems/running-sum-of-1d-array/
 *  */

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int N = nums.size()
        for(int i = 1; i < N; i++){
            for(int j = 0; j < N; j++){
                nums[i] = nums[i] + nums[j];
            }
        }
        return nums
    }
};