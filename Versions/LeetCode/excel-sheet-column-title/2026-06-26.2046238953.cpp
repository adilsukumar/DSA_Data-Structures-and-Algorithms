/*
 * Platform: LeetCode
 * Submission: 2046238953
 * Problem: Excel Sheet Column Title
 * Verdict: Accepted
 * Submitted: 2026-06-26
 * Recorded in repository: 2026-09-24
 * URL: https://leetcode.com/problems/excel-sheet-column-title/
 *  */

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