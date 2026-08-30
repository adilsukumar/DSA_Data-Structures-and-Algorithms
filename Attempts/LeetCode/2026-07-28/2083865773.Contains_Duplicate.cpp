/*
 * Platform: LeetCode
 * Submission: 2083865773
 * Problem: Contains Duplicate
 * Verdict: Time Limit Exceeded
 * Date: 2026-07-28
 * URL: https://leetcode.com/problems/contains-duplicate/
 *  */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] == nums[j]){
                    return true;
                }
            }
        }
        return false;
    }
};