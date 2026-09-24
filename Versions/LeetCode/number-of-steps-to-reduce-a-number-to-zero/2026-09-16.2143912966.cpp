/*
 * Platform: LeetCode
 * Submission: 2143912966
 * Problem: Number of Steps to Reduce a Number to Zero
 * Verdict: Accepted
 * Submitted: 2026-09-16
 * Recorded in repository: 2026-09-24
 * URL: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
 *  */

class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while(num > 0){
            if(num%2 == 0){
                num /= 2;
                count += 1;
            }
            else{
                num -= 1;
                count += 1;
            }
        }
        return count;
    }
};