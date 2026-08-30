/*
 * LeetCode 136 - Single Number [Easy]
 *
 * @platform   LeetCode
 * @id         136
 * @title      Single Number
 * @difficulty Easy
 * @topics     Array, Bit Manipulation
 * @pattern    XOR Accumulation
 * @url        https://leetcode.com/problems/single-number/
 * @solved     2026-06-23
 *
 * Problem
 * Given a non-empty array where every element appears twice except for one element
 * that appears exactly once, return that single element.
 *
 * Approach
 * This rides on three properties of bitwise XOR (^): 1. x ^ x = 0 a value XOR'd with
 * itself vanishes 2.
 *
 * Complexity
 * Time: O(n) -- exactly one pass, one O(1) XOR per element.
 * Space: O(1) -- a single int accumulator, independent of input size.
 *
 * Notes
 * - Single-element array [7]: loop runs once, 0 ^ 7 = 7.
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int repeat = 0;

        for(int i = 0; i < nums.size(); i++){
            repeat ^= nums[i];
        }
        return repeat;
    }
};
