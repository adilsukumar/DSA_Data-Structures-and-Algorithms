/*
 * Platform: LeetCode
 * Submission: 2043874693
 * Problem: Single Number
 * Verdict: Compile Error
 * Date: 2026-06-24
 * URL: https://leetcode.com/problems/single-number/
 *  */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int repeat = 0;

        for(int i = 0; i < nums.size(); i++){
            repeat ^= i;
        }
        return repeat
    }
};