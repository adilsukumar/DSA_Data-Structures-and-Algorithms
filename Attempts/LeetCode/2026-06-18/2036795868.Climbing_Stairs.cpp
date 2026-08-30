/*
 * Platform: LeetCode
 * Submission: 2036795868
 * Problem: Climbing Stairs
 * Verdict: Wrong Answer
 * Date: 2026-06-18
 * URL: https://leetcode.com/problems/climbing-stairs/
 *  */

class Solution {
public:
    int climbStairs(int n) {
        int count = 0;
        if(n == 2){
            count += 2;
            return count;
        }
        else if(n < 2){
            count += 1;
            return count;
        }
        else{
            count += (n-1) + (n-2);
            return count;
        }
        return 0;
    }
};