/* ============================================================================
 * CodeChef DNATION - Chef And Donation                          Difficulty 305
 * ----------------------------------------------------------------------------
 * @platform   CodeChef
 * @id         DNATION
 * @title      Chef And Donation
 * @difficulty 305
 * @topics     Basic Math, Implementation
 * @pattern    Per-test subtraction (Y - X)
 * @url        https://www.codechef.com/problems/DNATION
 * @solved     2026-06-13
 * ----------------------------------------------------------------------------
 * PROBLEM
 *   For each test case you are given two integers X and Y, where X is the
 *   amount Chef currently has and Y is the amount Chef wants to reach (the
 *   donation target). Print how much MORE Chef needs, i.e. Y - X. The problem
 *   guarantees Y >= X, so the answer is always non-negative.
 *
 *   Example: X = 30, Y = 100  ->  needs 70 more  ->  print 70.
 *
 * INTUITION
 *   "How much is still missing to go from X up to Y" is exactly the gap
 *   between them on the number line: Y - X. There is no state to carry
 *   between test cases, no ordering, no search -- each query is answered by a
 *   single subtraction, so the whole task is a thin loop over independent
 *   arithmetic. It works because the target minus the current holding is the
 *   definition of the shortfall.
 *
 * WALKTHROUGH (this code, line by line)
 *   - `int T, X, Y;`      : three plain ints. Values here fit in 32-bit; see
 *                           EDGE CASES for when that assumption is fragile.
 *   - `cin >> T;`         : read the number of test cases.
 *   - `for i in [0, T)`   : one iteration per test case.
 *       - `cin >> X;`     : current amount.
 *       - `cin >> Y;`     : target amount.
 *       - `cout << Y - X` : print the shortfall, newline via `endl`.
 *   - The reused X, Y each iteration is fine -- nothing depends on the
 *     previous test case, so overwriting is correct, not a bug.
 *
 *   Dry run on:
 *       2
 *       30 100
 *       50 50
 *   T = 2.
 *     i=0: X=30, Y=100 -> prints 100 - 30 = 70
 *     i=1: X=50, Y=50  -> prints 50  - 50 = 0
 *   Output:
 *       70
 *       0
 *
 * COMPLEXITY
 *   Time : O(T) -- constant work (one subtraction, one print) per test case.
 *   Space: O(1) -- three scalars reused; no arrays or buffers grow with input.
 *
 * EDGE CASES
 *   - Y == X: prints 0 (already at target). Handled naturally.
 *   - Y <  X: would print a negative number. The statement promises Y >= X,
 *     so this never occurs on valid input; the code does not defend against it.
 *   - Large values: if X or Y ever exceeded ~2.1e9, `int` would overflow.
 *     For this problem's constraints `int` is safe, but `long long` would be
 *     the defensive choice and costs nothing here.
 *   - `endl` flushes the stream every line. Correct, but on very large T it is
 *     slower than emitting '\n'; irrelevant at this problem's scale.
 *
 * NOTE
 *   This solution is already optimal: the answer is a single arithmetic
 *   operation per query and O(T) is the lower bound (every test case must be
 *   read). Nothing to improve algorithmically. The one stylistic tweak for
 *   heavy-I/O habits would be `'\n'` instead of `endl` plus
 *   `ios_base::sync_with_stdio(false); cin.tie(nullptr);`, but it changes no
 *   asymptotics and is unnecessary for rating-305 constraints.
 * ============================================================================ */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    cout << Y-X << endl;

	}

	return 0;

}
