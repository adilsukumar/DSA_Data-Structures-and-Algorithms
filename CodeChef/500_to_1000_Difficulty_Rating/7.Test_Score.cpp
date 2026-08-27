/*
 * ============================================================================
 * CodeChef CHEFSCORE - Test Score                                  [Rating 610]
 * ============================================================================
 *
 * @platform   CodeChef
 * @id         CHEFSCORE
 * @title      Test Score
 * @difficulty 610
 * @topics     Math, Basic Programming
 * @pattern    Divisibility + Range Check
 * @url        https://www.codechef.com/problems/CHEFSCORE
 * @solved     2026-06-30
 *
 * ----------------------------------------------------------------------------
 * PROBLEM
 * ----------------------------------------------------------------------------
 * Chef sits N tests. Each test is graded all-or-nothing: he either earns the
 * full X marks or 0 marks on it. Given a target total Y, decide whether Chef
 * can end up with EXACTLY Y marks summed across the N tests. Print YES/NO per
 * test case.
 *
 * Worked example: N=3, X=5, Y=10. Chef can ace exactly 2 of the 3 tests
 * (5 + 5 + 0 = 10), so the answer is YES. But Y=12 is impossible because
 * every achievable total is a multiple of 5.
 *
 * ----------------------------------------------------------------------------
 * INTUITION
 * ----------------------------------------------------------------------------
 * If each test contributes either 0 or X, then after k aced tests (0 <= k <= N)
 * the total is exactly k*X. So the set of ALL reachable totals is:
 *     { 0, X, 2X, 3X, ..., N*X }
 * A target Y is reachable iff it lands on one of those points. Two conditions
 * pin that down without ever looping over k:
 *   1. Y must be a multiple of X          -> Y % X == 0   (it's some k*X)
 *   2. That multiple must not exceed N     -> Y <= N*X     (k = Y/X <= N)
 * Together they say: Y/X is an integer AND at most N. That is the whole problem.
 * Note Y >= 0 is guaranteed by constraints, so k = Y/X is automatically >= 0.
 *
 * ----------------------------------------------------------------------------
 * WALKTHROUGH (this code)
 * ----------------------------------------------------------------------------
 *   cin >> T;                          read number of test cases
 *   for i in [0, T):
 *       cin >> N >> X >> Y;            per case: count, per-test marks, target
 *       if (N*X >= Y && Y % X == 0)    condition 1 (range) AND condition 2 (divisible)
 *           print YES
 *       else
 *           print NO
 *
 * The two clauses map exactly onto the two intuition checks:
 *   - N*X >= Y  ensures the target does not exceed the maximum reachable total.
 *   - Y % X == 0 ensures the target sits on a grid point (a whole number of
 *     aced tests), not between two of them.
 * Short-circuit order does not matter here since both must hold anyway.
 *
 * Dry run on T=1, N=3, X=5, Y=10:
 *   N*X = 15;  15 >= 10  -> true
 *   10 % 5 = 0           -> true
 *   both true            -> "YES"
 * Contrast Y=12: 15 >= 12 true, but 12 % 5 = 2 != 0 -> "NO".
 * Contrast Y=20: 20 % 5 = 0 true, but 15 >= 20 false -> "NO".
 *
 * ----------------------------------------------------------------------------
 * COMPLEXITY
 * ----------------------------------------------------------------------------
 * Time:  O(T) overall - a fixed handful of arithmetic ops per test case.
 * Space: O(1) - four scalar ints reused across every iteration; nothing stored.
 *
 * ----------------------------------------------------------------------------
 * EDGE CASES
 * ----------------------------------------------------------------------------
 * - Y = 0: 0 % X == 0 and N*X >= 0, so YES (ace zero tests). Handled correctly.
 * - Y = N*X (perfect score): N*X >= Y holds with equality and it's a multiple
 *   of X, so YES. Handled.
 * - X = 0 would make Y % X undefined behavior (division by zero). The problem's
 *   constraints guarantee X >= 1, so this cannot occur, but the code itself has
 *   no guard - worth remembering if the constraints ever change.
 * - Overflow: N*X is computed in `int`. Fine while N*X stays under ~2.1e9
 *   (true for this problem's constraints). If either bound grew large this
 *   product could overflow; promoting to `long long` would be the safe fix.
 *
 * This solution is already optimal - O(1) per query with a direct closed-form
 * test - so there is no better approach to sketch.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, X, Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N >> X >> Y;

	    if(N*X >= Y && Y%X == 0){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	    

	}



}
