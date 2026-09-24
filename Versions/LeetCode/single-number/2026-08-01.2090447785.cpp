/*
 * Platform: LeetCode
 * Submission: 2090447785
 * Problem: Single Number
 * Verdict: Accepted
 * Submitted: 2026-08-01
 * Recorded in repository: 2026-09-24
 * URL: https://leetcode.com/problems/single-number/
 *  */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int repeat = 0;

        for(int i = 0; i < nums.size(); i++){
            repeat ^= nums[i];
        }
        return repeat;
    }
};