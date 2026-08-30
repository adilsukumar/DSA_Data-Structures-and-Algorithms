/*
 * LeetCode 9 - Palindrome Number [Easy]
 *
 * @platform   LeetCode
 * @id         9
 * @title      Palindrome Number
 * @difficulty Easy
 * @topics     Math
 * @pattern    Digit Reversal
 * @url        https://leetcode.com/problems/palindrome-number/
 * @solved     2026-06-05
 *
 * Problem
 * Return true if integer `x` reads the same forwards and backwards.
 *
 * Approach
 * A number is a palindrome exactly when reversing its digits gives you the same number
 * back. So: build the reverse arithmetically, then compare.
 *
 * Complexity
 * Time: O(log10 x) -- one iteration per digit, so ~10 iterations at 32-bit max.
 * Space: O(1) -- three scalars, no array or string allocated.
 *
 * Notes
 * - x = 0 -> loop body never runs, rev stays 0, 0 == 0 -> true.
 * - Reversing only half the digits avoids overflow and does fewer iterations.
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int original = x;
        long long rev = 0;

        while (x != 0) {
            rev = rev * 10 + x % 10;
            x = x / 10;
        }

        return original == rev;
    }
};
