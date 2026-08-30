/*
 * Platform: LeetCode
 * Submission: 2043873336
 * Problem: Single Number
 * Verdict: Wrong Answer
 * Date: 2026-06-24
 * URL: https://leetcode.com/problems/single-number/
 *  */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int repeat = 0;
        for(int i = 0; i < nums.size(); i++){
            repeat = nums[i];
            if(repeat != nums[i]){
                i++;
            }
        }
        return repeat;
    }
};