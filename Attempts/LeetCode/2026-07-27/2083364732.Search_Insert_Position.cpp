/*
 * Platform: LeetCode
 * Submission: 2083364732
 * Problem: Search Insert Position
 * Verdict: Compile Error
 * Date: 2026-07-27
 * URL: https://leetcode.com/problems/search-insert-position/
 *  */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int N = nums.size();
        mid = N/2 - 1;
        for(int i = 0; i < mid; i++){
            low = nums[0];
            high = nums[mid - 1];
            for(int j = low; j <= high; j++){
                if(target == nums[j]){
                    return j;
                }
            }
        }
        for(int i = 0; i > mid; i++){
            low = nums[mid + 1];
            high = nums[-1];
            for(int j = low; j <= high; j++){
                if(target == nums[j]){
                    return j;
                }
            }
        }
    }
};