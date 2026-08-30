/*
 * LeetCode 70 - Climbing Stairs [Easy]
 *
 * @platform   LeetCode
 * @id         70
 * @title      Climbing Stairs
 * @difficulty Easy
 * @topics     Math, Dynamic Programming, Memoization
 * @pattern    Bottom-Up DP (Fibonacci)
 * @url        https://leetcode.com/problems/climbing-stairs/
 * @solved     2026-06-17
 *
 * Problem
 * You are climbing a staircase with n steps.
 *
 * Approach
 * To reach step i, the final move came from i-1 or i-2. Therefore
 * ways[i] = ways[i-1] + ways[i-2], which the code computes bottom-up.
 *
 * Complexity
 * Time: O(n) - single pass filling one dp entry per step.
 * Space: O(n) - the dp array holds all n+1 entries.
 *
 * Notes
 * - n = 1, n = 2: handled by the early return, before any dp[1]/dp[2] access.
 * - Only the previous two values are needed, so space can be reduced to O(1).
 */

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
