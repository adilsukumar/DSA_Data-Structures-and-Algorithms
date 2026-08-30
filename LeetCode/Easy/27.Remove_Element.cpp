/*
 * LeetCode 27 - Remove Element [Easy]
 *
 * @platform   LeetCode
 * @id         27
 * @title      Remove Element
 * @difficulty Easy
 * @topics     Array, Two Pointers
 * @pattern    Fast / Slow Read-Write Pointers
 * @url        https://leetcode.com/problems/remove-element/
 * @solved     2026-06-11
 *
 * Problem
 * Remove all occurrences of `val` from `nums` IN PLACE and return k, the count of
 * remaining elements.
 *
 * Approach
 * "Removing" from an array in place is really COMPACTION: you cannot delete a slot, so
 * instead you copy everything you want to keep to the front, in order, and report how far
 * the keepers reach.
 *
 * Complexity
 * Time: O(n) -- one pass, one comparison per element.
 * Space: O(1) -- two integers, no allocation.
 *
 * Notes
 * - Empty array -> loop never runs, returns 0.
 */

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
