/*
 * Platform: LeetCode
 * Submission: 2150104705
 * Problem: Subtract the Product and Sum of Digits of an Integer
 * Verdict: Accepted
 * Submitted: 2026-09-22
 * Recorded in repository: 2026-09-24
 * URL: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
 *  */

class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;
        for(int i = 0; i < (to_string(n)).size(); i++){
            string s = to_string(n);
            prod *= s[i]-'0';
            sum += s[i]-'0';
        }
        return prod-sum;
    }
};