/*
 * Platform: LeetCode
 * Submission: 2035663353
 * Problem: Sqrt(x)
 * Verdict: Accepted
 * Submitted: 2026-06-17
 * Recorded in repository: 2026-09-24
 * Variant: Brute Force (inferred from submission order)
 * URL: https://leetcode.com/problems/sqrtx/
 *  */

#include <cmath>
class Solution {
public:
    int mySqrt(int x) {
        int a, b;
        a = sqrt(x);
        b = floor(a);
        return b;
    }
};