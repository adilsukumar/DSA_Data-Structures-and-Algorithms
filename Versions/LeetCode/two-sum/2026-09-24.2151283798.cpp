/*
 * Platform: LeetCode
 * Submission: 2151283798
 * Problem: Two Sum
 * Verdict: Accepted
 * Submitted: 2026-09-24
 * Recorded in repository: 2026-09-24
 * Variant: Optimized (inferred from submission order)
 * URL: https://leetcode.com/problems/two-sum/
 *  */

class Solution {

public:

    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> freq;

        for(int i=0;i<nums.size();i++){

            int complement = target - nums[i];

            if(freq.find(complement) != freq.end()){

                return {freq[complement], i};

            }

            freq[nums[i]] = i;

        }

        return {};

    }

};