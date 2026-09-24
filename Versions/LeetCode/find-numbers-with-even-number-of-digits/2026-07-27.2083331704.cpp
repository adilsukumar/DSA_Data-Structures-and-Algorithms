/*
 * Platform: LeetCode
 * Submission: 2083331704
 * Problem: Find Numbers with Even Number of Digits
 * Verdict: Accepted
 * Submitted: 2026-07-27
 * Recorded in repository: 2026-09-24
 * Variant: Optimized (inferred from submission order)
 * URL: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
 *  */

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int digits = 1;
            int num = nums[i];
            while(num / 10 != 0){
                digits += 1;
                num /= 10;
            }
            if(digits % 2 == 0){
                count += 1;
            }
        }
        return count;
    }
};