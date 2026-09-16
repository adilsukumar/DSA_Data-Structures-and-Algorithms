/*
 * Platform: LeetCode
 * Submission: 2143932322
 * Problem: Subtract the Product and Sum of Digits of an Integer
 * Verdict: Compile Error
 * Date: 2026-09-16
 * URL: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
 *  */

class Solution {
public:
    int subtractProductAndSum(int n) {
        string prod = "1";
        string sum = "0";
        for(int i = 0; i < (to_string(n)).size(); i++){
            prod *= n[i];
            sum += n[i];
        }
        return prod-sum;
    }
};