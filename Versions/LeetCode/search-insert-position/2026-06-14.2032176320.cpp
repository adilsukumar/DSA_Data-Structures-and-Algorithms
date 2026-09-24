/*
 * Platform: LeetCode
 * Submission: 2032176320
 * Problem: Search Insert Position
 * Verdict: Accepted
 * Submitted: 2026-06-14
 * Recorded in repository: 2026-09-24
 * URL: https://leetcode.com/problems/search-insert-position/
 *  */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                return i;
            }
            else{
                if(target < nums[i]){
                    return i;
                }
            }
        }
        return nums.size();
    }
};