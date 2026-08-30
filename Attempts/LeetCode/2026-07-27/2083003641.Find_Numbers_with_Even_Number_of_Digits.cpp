/*
 * Platform: LeetCode
 * Submission: 2083003641
 * Problem: Find Numbers with Even Number of Digits
 * Verdict: Compile Error
 * Date: 2026-07-27
 * URL: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
 *  */

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        sort(nums[0], nums.size(), greater<int>());
        int max_digitsno = nums[0];
        for(int i = 0; i < nums.size(); i++){
            int highest = 0;
            for(int j = 0; j < max_digitsno; j++){
                if(nums[i][j] > 0){
                    highest += 1;
                }
            }
            return highest;
        }
    }
};