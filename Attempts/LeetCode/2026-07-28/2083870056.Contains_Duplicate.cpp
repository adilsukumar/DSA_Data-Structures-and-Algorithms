/*
 * Platform: LeetCode
 * Submission: 2083870056
 * Problem: Contains Duplicate
 * Verdict: Compile Error
 * Date: 2026-07-28
 * URL: https://leetcode.com/problems/contains-duplicate/
 *  */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        if(s == nums){
            return false;
        }
        else{
            return true;
        }
    }
};