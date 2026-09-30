/*
 * Platform: LeetCode
 * Submission: 2158406443
 * Problem: Move Zeroes
 * Verdict: Compile Error
 * Date: 2026-09-30
 * URL: https://leetcode.com/problems/move-zeroes/
 *  */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pointerb = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                nums[i] = nums[pointerb];
                nums[pointerb] = 0;
                pointerb--; 
            }
        }
        return nums;
    }
};