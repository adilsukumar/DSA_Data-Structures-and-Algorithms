/*
 * Platform: LeetCode
 * Submission: 2083856400
 * Problem: Search Insert Position
 * Verdict: Compile Error
 * Date: 2026-07-28
 * URL: https://leetcode.com/problems/search-insert-position/
 *  */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int N = nums.size();
        int mid = N/2;
        for(int i = 0; i < N; i++){
            if(target > nums[mid]){
                int high_aftermid = nums[N-1];
                int low_aftermid = nums[mid];
                for(int j = low_aftermid; j <= high_aftermid; j++){
                    if(target == nums[j]){
                        return j;
                    }
                }
            }
            else if(target == nums[mid]){
                return mid;
            }
            else{
                int low_beforemid = nums[0];
                int high_beforemid = nums[mid];
                for(int k = low_beforemid; k <= high_beforemid; k++){
                    if(target == nums[k]){
                        return k;
                    }
                }
            }
        }
    }
};