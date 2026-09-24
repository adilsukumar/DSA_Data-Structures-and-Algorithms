/*
 * Platform: LeetCode
 * Submission: 2083871358
 * Problem: Contains Duplicate
 * Verdict: Accepted
 * Submitted: 2026-07-28
 * Recorded in repository: 2026-09-24
 * URL: https://leetcode.com/problems/contains-duplicate/
 *  */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        if(nums.size() == s.size()){
            return false;
        }
        else{
            return true;
        }
    }
};