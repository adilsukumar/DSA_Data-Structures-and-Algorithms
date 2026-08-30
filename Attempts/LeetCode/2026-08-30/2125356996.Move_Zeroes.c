/*
 * Platform: LeetCode
 * Submission: 2125356996
 * Problem: Move Zeroes
 * Verdict: Compile Error
 * Date: 2026-08-30
 * URL: https://leetcode.com/problems/move-zeroes/
 *  */

void moveZeroes(int* nums, int numsSize) {
    int i, j;
    for(i = 0; i < nums.length(); i++){
        for(j = i+1; j < nums.length(), j++){
            if(nums[i] == 0){
                temp = nums[nums.length() - 1];
                nums[nums.length() - 1] = nums[i];
                nums[i] = temp;
            }
            if(nums[i] > nums[j] && nums[i] != 0){
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}