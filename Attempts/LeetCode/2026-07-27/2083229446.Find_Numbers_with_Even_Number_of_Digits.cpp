/*
 * Platform: LeetCode
 * Submission: 2083229446
 * Problem: Find Numbers with Even Number of Digits
 * Verdict: Runtime Error
 * Date: 2026-07-27
 * URL: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
 *  */

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int digits = 0;
            while(nums[i] / 10 != 0){
                digits += 1;
            }
            if(digits % 2 == 0){
                count += 1;
            }
        }
        return count;
    }
};