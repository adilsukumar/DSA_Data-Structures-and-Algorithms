/*
 * Platform: LeetCode
 * Submission: 2036811765
 * Problem: Climbing Stairs
 * Verdict: Accepted
 * Submitted: 2026-06-18
 * Recorded in repository: 2026-09-24
 * URL: https://leetcode.com/problems/climbing-stairs/
 *  */

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        if(n <= 2){
            return n;
        }
        else{
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