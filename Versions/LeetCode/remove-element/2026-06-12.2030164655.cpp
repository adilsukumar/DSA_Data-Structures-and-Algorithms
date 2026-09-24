/*
 * Platform: LeetCode
 * Submission: 2030164655
 * Problem: Remove Element
 * Verdict: Accepted
 * Submitted: 2026-06-12
 * Recorded in repository: 2026-09-24
 * Variant: Optimized (inferred from submission order)
 * URL: https://leetcode.com/problems/remove-element/
 *  */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};