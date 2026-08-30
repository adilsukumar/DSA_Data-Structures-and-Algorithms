/*
 * Platform: LeetCode
 * Submission: 2036798347
 * Problem: Climbing Stairs
 * Verdict: Compile Error
 * Date: 2026-06-18
 * URL: https://leetcode.com/problems/climbing-stairs/
 *  */

class Solution {
public:
    int climbStairs(int n) {
        int count = 0;
        for(int i = 0; i < n; i++){
            if(i == 2){
                count += 2;
            }
            else if(i < 2){
                count += 1;
            }
            else{
                count += (n-i[1]) + (n-i[0]);
            }
        return count;
        }
    }
};