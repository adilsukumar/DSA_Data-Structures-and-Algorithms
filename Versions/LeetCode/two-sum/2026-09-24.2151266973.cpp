/*
 * Platform: LeetCode
 * Submission: 2151266973
 * Problem: Two Sum
 * Verdict: Accepted
 * Submitted: 2026-09-24
 * Recorded in repository: 2026-09-24
 * Variant: Improved Approach 3 (inferred from submission order)
 * URL: https://leetcode.com/problems/two-sum/
 *  */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            int needed = target - nums[i];
            if(freq.count(needed)){
                return {freq[needed],i};
            }
            freq[nums[i]] = i;
        }
        return {};
    }
};