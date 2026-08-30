/*
 * LeetCode 171 - Excel Sheet Column Number [Easy]
 *
 * @platform   LeetCode
 * @id         171
 * @title      Excel Sheet Column Number
 * @difficulty Easy
 * @topics     Math, String
 * @pattern    Base-26 Positional Decoding (Horner)
 * @url        https://leetcode.com/problems/excel-sheet-column-number/
 * @solved     2026-06-26
 *
 * Problem
 * Excel labels its columns A, B, ..., Z, AA, AB, ..., AZ, BA, ...
 *
 * Approach
 * This is a positional number system, like decimal but base 26. In base 10 the string "28"
 * means 2*10 + 8.
 *
 * Complexity
 * Time: O(n), n = length of columnTitle.
 * Space: O(1).
 *
 * Notes
 * - Single letter ("A"): loop runs once, ans = 0*26+1 = 1.
 */

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;

        for (char ch : columnTitle) {
            ans = ans * 26 + (ch - 'A' + 1);
        }

        return ans;
    }
};
