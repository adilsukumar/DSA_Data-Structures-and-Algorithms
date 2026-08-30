/*
 * Platform: LeetCode
 * Submission: 2036787917
 * Problem: Climbing Stairs
 * Verdict: Compile Error
 * Date: 2026-06-18
 * URL: https://leetcode.com/problems/climbing-stairs/
 *  */

class Solution {
public:
    int climbStairs(int n) {
       int count = 1;
       if(n > 1){
        if(n/2.0 > 0){
            count += 2;
            return count;
        }
       }
       else{
        return count;
       }
    }
};