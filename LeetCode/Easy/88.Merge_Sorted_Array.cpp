/*
 * LeetCode 88 - Merge Sorted Array [Easy]
 *
 * @platform   LeetCode
 * @id         88
 * @title      Merge Sorted Array
 * @difficulty Easy
 * @topics     Array, Two Pointers, Sorting
 * @pattern    Concatenate then full sort
 * @url        https://leetcode.com/problems/merge-sorted-array/
 * @solved     2026-06-19
 *
 * Problem
 * You are given two sorted (non-decreasing) integer arrays.
 *
 * Approach
 * Copy nums2 into the unused tail of nums1, then sort the full array. This is correct but
 * does not use the fact that both inputs are already sorted.
 *
 * Complexity
 * Time: O((m + n) log(m + n)) -- the copy loop is O(n), but the full sort over all m + n
 * elements dominates.
 * Space: O(1) auxiliary -- writes happen inside nums1; sort() is typically in-place
 * (introsort), ignoring its O(log n) recursion stack.
 *
 * Notes
 * - n == 0 (nothing to merge): the loop runs zero times, sort() re-sorts an already-sorted
 *   nums1 harmlessly.
 * - Merge from the back with three pointers for O(m + n) time and O(1) extra space.
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        for(int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }
};
