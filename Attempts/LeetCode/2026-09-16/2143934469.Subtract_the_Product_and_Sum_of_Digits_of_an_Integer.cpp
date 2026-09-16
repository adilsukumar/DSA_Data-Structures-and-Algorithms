/*
 * Platform: LeetCode
 * Submission: 2143934469
 * Problem: Subtract the Product and Sum of Digits of an Integer
 * Verdict: Wrong Answer
 * Date: 2026-09-16
 * URL: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
 *  */

class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;
        for(int i = 0; i < (to_string(n)).size(); i++){
            string s = to_string(n);
            prod *= s[i];
            sum += s[i];
        }
        return prod-sum;
    }
};