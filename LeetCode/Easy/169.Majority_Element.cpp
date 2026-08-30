/*
 * LeetCode 169 - Majority Element [Easy]
 *
 * @platform   LeetCode
 * @id         169
 * @title      Majority Element
 * @difficulty Easy
 * @topics     Array, Hash Table, Divide and Conquer, Sorting, Counting
 * @pattern    Sort + Middle Element
 * @url        https://leetcode.com/problems/majority-element/
 * @solved     2026-06-24
 *
 * Problem
 * Given an array `nums` of size n, return the "majority element" -- the value that appears
 * STRICTLY MORE than floor(n/2) times.
 *
 * Approach
 * If one value occupies more than half the array, then after SORTING, that value forms a
 * single contiguous run longer than n/2. A run of length > n/2 is so long it must cover
 * the center of the array no matter where it starts.
 *
 * Complexity
 * Time: O(n log n) -- dominated by the sort; the index lookup is O(1).
 * Space: O(1) auxiliary if the sort is in-place (introsort typically uses O(log n)
 * recursion stack).
 *
 * Notes
 * - Single element [x]: half = 0, returns x.
 * - Boyer-Moore finds the majority in O(n) time and O(1) space without sorting.
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int half = nums.size()/2;
        return nums[half];
    }
};
