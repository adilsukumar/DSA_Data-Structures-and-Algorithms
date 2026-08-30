/*
 * Platform: LeetCode
 * Submission: 2090561642
 * Problem: Max Consecutive Ones
 * Verdict: Wrong Answer
 * Date: 2026-08-02
 * URL: https://leetcode.com/problems/max-consecutive-ones/
 *  */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 1; j <= i; j++){
                if(nums[i] == 1 && nums[j] == 1){
                    count += 1;
                }
            }
        }
        return count;
    }
};