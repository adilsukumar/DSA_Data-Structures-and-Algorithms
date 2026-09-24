/*
 * Platform: LeetCode
 * Submission: 2022658661
 * Problem: Two Sum
 * Verdict: Accepted
 * Submitted: 2026-06-05
 * Recorded in repository: 2026-09-24
 * Variant: Brute Force (inferred from submission order)
 * URL: https://leetcode.com/problems/two-sum/
 *  */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        
        for (int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[i]+nums[j] == target)
                {
                    return {i,j};
                }
                
            }
        }
        return {};
    }   
        
};