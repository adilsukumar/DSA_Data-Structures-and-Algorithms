/*
 * Platform: LeetCode
 * Submission: 2083365871
 * Problem: Search Insert Position
 * Verdict: Compile Error
 * Date: 2026-07-27
 * URL: https://leetcode.com/problems/search-insert-position/
 *  */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int N = nums.size();
        int mid = N/2 - 1;
        for(int i = 0; i < mid; i++){
            int low_beforemid = nums[0];
            int high_beforemid = nums[mid - 1];
            for(int j = low_beforemid; j <= high_beforemid; j++){
                if(target == nums[j]){
                    return j;
                }
            }
        }
        for(int i = 0; i > mid; i++){
            int low_aftermid = nums[mid + 1];
            int high_aftermid = nums[-1];
            for(int j = low_aftermid; j <= high_aftermid; j++){
                if(target == nums[j]){
                    return j;
                }
            }
        }
    }
};