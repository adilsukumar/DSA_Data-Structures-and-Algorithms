/*
 * Platform: LeetCode
 * Submission: 2143927825
 * Problem: Subtract the Product and Sum of Digits of an Integer
 * Verdict: Compile Error
 * Date: 2026-09-16
 * URL: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
 *  */

class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;
        for(int i = 0; i < (to_string(n).size(); i++){
            prod *= i;
            sum += i;
        }
        return prod-sum;
    }
};