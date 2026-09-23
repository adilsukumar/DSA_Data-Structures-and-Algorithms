/*
 * Platform: LeetCode
 * Submission: 2151260904
 * Problem: Two Sum
 * Verdict: Wrong Answer
 * Date: 2026-09-23
 * URL: https://leetcode.com/problems/two-sum/
 *  */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            int needed = target - nums[i];
            if(freq.count(needed)){
                return {needed,i};
            }
            else{
                i++;
            }
        }
        return {};
    }
};