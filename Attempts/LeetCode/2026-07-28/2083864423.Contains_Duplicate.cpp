/*
 * Platform: LeetCode
 * Submission: 2083864423
 * Problem: Contains Duplicate
 * Verdict: Compile Error
 * Date: 2026-07-28
 * URL: https://leetcode.com/problems/contains-duplicate/
 *  */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = 1; j < nums.size(); j++){
                if(nums[i] == nums[j]){
                    return True;
                }
                else{
                    return False;
                }
            }
        }
    }
};