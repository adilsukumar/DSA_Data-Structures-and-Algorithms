/*
 * LeetCode 1281 - Subtract the Product and Sum of Digits of an Integer [Easy]
 *
 * @platform   LeetCode
 * @id         1281
 * @title      Subtract the Product and Sum of Digits of an Integer
 * @difficulty Easy
 * @topics     Math
 * @pattern    Digit Processing
 * @url        https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
 * @solved     2026-09-16
 *
 * Problem
 * Accepted solution for Subtract the Product and Sum of Digits of an Integer.
 *
 * Approach
 * The code converts the integer to a string once implicitly but in the provided
 * snippet calls to_string(n) repeatedly inside the loop. It iterates through each
 * character of the string representation of the number, calculating the product of
 * the digits (converting characters back to integers via subtraction of '0') and
 * the sum of the digits simultaneously in a single pass, and finally returns the
 * difference between the product and the sum.
 *
 * Complexity
 * Time: O(d^2) Space: O(d)
 */

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
