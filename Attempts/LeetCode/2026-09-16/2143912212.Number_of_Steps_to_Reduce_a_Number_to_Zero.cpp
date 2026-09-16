/*
 * Platform: LeetCode
 * Submission: 2143912212
 * Problem: Number of Steps to Reduce a Number to Zero
 * Verdict: Wrong Answer
 * Date: 2026-09-16
 * URL: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
 *  */

class Solution {
public:
    int numberOfSteps(int num) {
        while(num > 0){
            if(num%2 == 0){
                num /= 2;
            }
            else{
                num -= 1;
            }
        }
        return num;
    }
};