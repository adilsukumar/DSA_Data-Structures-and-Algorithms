/*
 * LeetCode 69 - Sqrt(x) [Easy]
 *
 * @platform   LeetCode
 * @id         69
 * @title      Sqrt(x)
 * @difficulty Easy
 * @topics     Math, Binary Search
 * @pattern    Library sqrt() truncated to int
 * @url        https://leetcode.com/problems/sqrtx/
 * @solved     2026-06-16
 *
 * Problem
 * Given a non-negative integer x, return floor(sqrt(x)).
 *
 * Approach
 * Call sqrt() and convert its non-negative floating-point result to int, which truncates
 * the fractional part.
 *
 * Complexity
 * Time: O(1) as written -- a single hardware/library sqrt call.
 * Space: O(1) -- no auxiliary storage.
 *
 * Notes
 * - x = 0, x = 1 : sqrt returns 0.0 / 1.0, truncates cleanly.
 * - For interview practice, use integer binary search with 64-bit multiplication.
 */

#include <cmath>
class Solution {
public:
    int mySqrt(int x) {
        return sqrt(x);
    }
};
