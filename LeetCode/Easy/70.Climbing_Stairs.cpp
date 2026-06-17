/*
 * ============================================================================
 * LeetCode 70 - Climbing Stairs                                    [Easy]
 * ============================================================================
 * @platform   LeetCode
 * @id         70
 * @title      Climbing Stairs
 * @difficulty Easy
 * @topics     Math, Dynamic Programming, Memoization
 * @pattern    Bottom-Up DP (Fibonacci)
 * @url        https://leetcode.com/problems/climbing-stairs/
 * @solved     2026-06-17
 *
 * ----------------------------------------------------------------------------
 * PROBLEM
 * ----------------------------------------------------------------------------
 * You are climbing a staircase with n steps. Each move you take either 1 step
 * or 2 steps. Count the number of DISTINCT ordered ways to reach the top.
 *
 *   n = 3  ->  3 ways:  (1,1,1)  (1,2)  (2,1)
 *   n = 4  ->  5 ways:  (1,1,1,1) (1,1,2) (1,2,1) (2,1,1) (2,2)
 *
 * Order matters, so (1,2) and (2,1) count separately.
 *
 * ----------------------------------------------------------------------------
 * INTUITION
 * ----------------------------------------------------------------------------
 * To land on step i, your final move was either a 1-step (from i-1) or a
 * 2-step (from i-2). Those two arrival routes are disjoint and together cover
 * every possibility, so:
 *
 *     ways(i) = ways(i-1) + ways(i-2)
 *
 * That is exactly the Fibonacci recurrence. The reason it works is the "no
 * double counting / no gaps" property: every path to i passes through exactly
 * one of {i-1, i-2} on its last hop, so summing the two subcounts is both
 * complete and non-overlapping. Base counts anchor it: 1 way to stand at step
 * 1, and 2 ways to reach step 2 ((1,1) and (2)).
 *
 * ----------------------------------------------------------------------------
 * WALKTHROUGH (this code)
 * ----------------------------------------------------------------------------
 * - vector<int> dp(n+1): dp[i] will hold ways to reach step i.
 * - if (n <= 2) return n: shortcut for n=1 (->1) and n=2 (->2). This also
 *   guards the else-branch, which assumes dp[1] and dp[2] are valid indices.
 * - dp[0] = 0: DEAD CODE. The recurrence starts at i=3 and only ever reads
 *   dp[i-1]/dp[i-2] down to dp[1], so dp[0] is never consumed. (Conceptually
 *   dp[0] "should" be 1 for the empty path, but this code sidesteps it via the
 *   n<=2 early return, so the wrong value here is harmless.)
 * - dp[1] = 1, dp[2] = 2: base cases seeded directly.
 * - for i in [3..n]: dp[i] = dp[i-1] + dp[i-2], filling the table upward.
 * - return dp[n].
 *
 * DRY RUN, n = 5:
 *   seed:  dp[1]=1, dp[2]=2
 *   i=3:   dp[3] = dp[2]+dp[1] = 2+1 = 3
 *   i=4:   dp[4] = dp[3]+dp[2] = 3+2 = 5
 *   i=5:   dp[5] = dp[4]+dp[3] = 5+3 = 8
 *   return dp[5] = 8   (correct: matches Fibonacci 1,2,3,5,8)
 *
 * ----------------------------------------------------------------------------
 * COMPLEXITY
 * ----------------------------------------------------------------------------
 * Time:  O(n)  - single pass filling one dp entry per step.
 * Space: O(n)  - the dp array holds all n+1 entries, though only the last two
 *                are ever needed at once (see optimization below).
 *
 * ----------------------------------------------------------------------------
 * EDGE CASES
 * ----------------------------------------------------------------------------
 * - n = 1, n = 2: handled by the early return, before any dp[1]/dp[2] access.
 *   This matters: without the guard, seeding dp[2] when n < 2 would write out
 *   of bounds (dp has size n+1). The return correctly protects the else-branch.
 * - n = 0: returns 0. Not in LeetCode's constraints (1 <= n <= 45); the
 *   "empty staircase = 1 way" convention is not modeled here.
 * - Overflow: within n <= 45, dp[45] = 1836311903 fits in int, so no overflow.
 *
 * ----------------------------------------------------------------------------
 * BETTER APPROACH (space)
 * ----------------------------------------------------------------------------
 * Time is already optimal at O(n). Space can drop to O(1) since each step only
 * needs the previous two values -- no full array required:
 *
 *     int climbStairs(int n) {
 *         if (n <= 2) return n;
 *         int prev2 = 1, prev1 = 2;      // ways to reach step 1 and step 2
 *         for (int i = 3; i <= n; i++) {
 *             int cur = prev1 + prev2;
 *             prev2 = prev1;
 *             prev1 = cur;
 *         }
 *         return prev1;
 *     }
 *
 * (For interviews: mention the O(log n) matrix-exponentiation / fast-doubling
 * trick if asked to push time below O(n).)
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
