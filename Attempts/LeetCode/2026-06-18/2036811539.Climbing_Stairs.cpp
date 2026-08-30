/*
 * Platform: LeetCode
 * Submission: 2036811539
 * Problem: Climbing Stairs
 * Verdict: Compile Error
 * Date: 2026-06-18
 * URL: https://leetcode.com/problems/climbing-stairs/
 *  */

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        else{
            vector<int> dp(n+1);
            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 2;
            for(int i = 3; i <=n; i++){
                dp[i] = dp[i-1] + dp[i-2];
            }
        }
        return dp[n];
    }
};