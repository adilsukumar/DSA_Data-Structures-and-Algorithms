/*
 * LeetCode 26 - Remove Duplicates from Sorted Array [Easy]
 *
 * @platform   LeetCode
 * @id         26
 * @title      Remove Duplicates from Sorted Array
 * @difficulty Easy
 * @topics     Array, Two Pointers
 * @pattern    In-Place Compaction (via std::unique)
 * @url        https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * @solved     2026-06-10
 *
 * Problem
 * Given a SORTED array, remove duplicates IN PLACE so each unique value appears once.
 *
 * Approach
 * Sortedness is the whole gift here. In a sorted array, equal values are always ADJACENT.
 *
 * Complexity
 * Time: O(n) -- std::unique makes exactly one pass, comparing each element to its
 * predecessor.
 * Space: O(1) -- compaction happens in place; no allocation.
 *
 * Notes
 * - Empty array -> begin() == end(), unique returns begin(), distance 0.
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = std::unique(nums.begin(), nums.end());
        return it - nums.begin();
    
    }
};
