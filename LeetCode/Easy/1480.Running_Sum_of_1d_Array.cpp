/*
 * LeetCode 1480 - Running Sum of 1d Array [Easy]
 *
 * @platform   LeetCode
 * @id         1480
 * @title      Running Sum of 1d Array
 * @difficulty Easy
 * @topics     Array, Prefix Sum
 * @pattern    In-Place Prefix Sum
 * @url        https://leetcode.com/problems/running-sum-of-1d-array/
 * @solved     2026-07-26
 *
 * Problem
 * Given an array nums, return its "running sum", where the value at index i is the sum of
 * every element from index 0 through i inclusive.
 *
 * Approach
 * A running sum is a prefix sum. The naive idea is: for each i, add up all elements 0..i
 * from scratch -- that repeats work and costs O(N^2).
 *
 * Complexity
 * Time: O(N) -- one pass, a single addition per element.
 * Space: O(1) extra -- mutates the input in place; no auxiliary array.
 *
 * Notes
 * - N == 1: the loop never runs (starts at i=1, condition 1 < 1 is false).
 */

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int N = nums.size();
        for(int i = 1; i < N; i++){
            nums[i] = nums[i] + nums[i-1];
        }
        return nums;
    }
};
