/*
 * Platform: LeetCode
 * Submission: 2023662170
 * Problem: Palindrome Number
 * Verdict: Runtime Error
 * Date: 2026-06-06
 * URL: https://leetcode.com/problems/palindrome-number/
 *  */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int original = x;
        int rev = 0;

        while (x != 0) {
            rev = rev * 10 + x % 10;
            x = x / 10;
        }

        return original == rev;
    }
};