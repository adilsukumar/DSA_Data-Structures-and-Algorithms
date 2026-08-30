/*
 * Platform: LeetCode
 * Submission: 2090561072
 * Problem: Max Consecutive Ones
 * Verdict: Compile Error
 * Date: 2026-08-02
 * URL: https://leetcode.com/problems/max-consecutive-ones/
 *  */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1 && nums[i+1] == 1){
                count += 1;
            }
        }
    }
};