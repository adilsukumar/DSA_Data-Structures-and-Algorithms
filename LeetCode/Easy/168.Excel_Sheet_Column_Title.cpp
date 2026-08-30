/*
 * LeetCode 168 - Excel Sheet Column Title [Easy]
 *
 * @platform   LeetCode
 * @id         168
 * @title      Excel Sheet Column Title
 * @difficulty Easy
 * @topics     Math, String
 * @pattern    Bijective Base-26 Conversion
 * @url        https://leetcode.com/problems/excel-sheet-column-title/
 * @solved     2026-06-25
 *
 * Problem
 * Given a positive integer, return its Excel column title, the label shown at the top of a
 * spreadsheet column.
 *
 * Approach
 * This looks like base-26 conversion, but it is NOT ordinary base-26. A normal positional
 * system has a digit for 0; here the smallest symbol 'A' maps to 1, and there is no symbol
 * for 0.
 *
 * Complexity
 * Time: O(log_26 n) - the value is divided by 26 each iteration, so the loop runs once per
 * output letter (at most ~7 for a 32-bit int).
 * Space: O(log_26 n) for the output string (O(1) auxiliary beyond it).
 *
 * Notes
 * - Single letters (1..26): loop runs once; 26 -> "Z" handled by the shift.
 */

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--;
            result = char(columnNumber % 26 + 'A') + result;
            columnNumber /= 26;
        }
        return result;
    }
};
