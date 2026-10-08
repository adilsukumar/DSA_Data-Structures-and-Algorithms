/*
 * Platform: LeetCode
 * Submission: 2165646318
 * Problem: Move Zeroes
 * Verdict: Wrong Answer
 * Date: 2026-10-07
 * URL: https://leetcode.com/problems/move-zeroes/
 *  */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pointerb = nums.size() - 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                nums[i] = nums[pointerb];
                nums[pointerb] = 0;
                pointerb--; 
            }
        }
    }
};