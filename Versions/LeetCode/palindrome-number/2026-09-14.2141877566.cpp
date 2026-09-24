/*
 * Platform: LeetCode
 * Submission: 2141877566
 * Problem: Palindrome Number
 * Verdict: Accepted
 * Submitted: 2026-09-14
 * Recorded in repository: 2026-09-24
 * Variant: Optimized (inferred from submission order)
 * URL: https://leetcode.com/problems/palindrome-number/
 *  */

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