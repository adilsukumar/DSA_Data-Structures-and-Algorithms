/*
 * Platform: LeetCode
 * Submission: 2151246296
 * Problem: Two Sum
 * Verdict: Compile Error
 * Date: 2026-09-23
 * URL: https://leetcode.com/problems/two-sum/
 *  */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = 1; j <= i; j++){
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
    }
};