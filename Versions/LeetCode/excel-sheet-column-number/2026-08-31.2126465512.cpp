/*
 * Platform: LeetCode
 * Submission: 2126465512
 * Problem: Excel Sheet Column Number
 * Verdict: Accepted
 * Submitted: 2026-08-31
 * Recorded in repository: 2026-09-24
 * URL: https://leetcode.com/problems/excel-sheet-column-number/
 *  */

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