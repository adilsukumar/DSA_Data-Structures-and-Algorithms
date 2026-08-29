/*
 * ============================================================================
 * CodeChef DONDRIVE - Donation Drive                         Difficulty: 272
 * ============================================================================
 * @platform   CodeChef
 * @id         DONDRIVE
 * @title      Donation Drive
 * @difficulty 272
 * @topics     Basic Math, Implementation
 * @pattern    Direct Subtraction
 * @url        https://www.codechef.com/problems/DONDRIVE
 * @solved     2026-06-06
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   A donation drive needs to raise a total of N (rupees/units). X has already
 *   been collected. Print how much MORE is still needed to hit the goal, i.e.
 *   the shortfall N - X. Repeated over T independent test cases.
 *
 *   Example: N = 100, X = 30  ->  answer 70 (still need 70 more).
 *            N = 50,  X = 50  ->  answer 0  (goal already met).
 *
 * INTUITION
 *   "Amount remaining" is just goal minus what you have: N - X. There is no
 *   state carried between test cases and no interaction between N and X beyond
 *   a single subtraction, so the whole problem collapses to one arithmetic op
 *   per query. The reason this is correct is definitional: the remaining
 *   contribution to reach a target from a current amount IS target - current.
 *
 * WALKTHROUGH  (this code, line by line)
 *   - cin >> T;                read the number of test cases.
 *   - for (i = 0; i < T; i++)  loop once per test case.
 *       cin >> N;  cin >> X;   read the goal N and the amount collected X.
 *       cout << N - X << endl; print the shortfall and a newline.
 *   - return 0;                normal exit.
 *
 *   The two separate `cin >> N;` / `cin >> X;` reads are equivalent to a single
 *   `cin >> N >> X;` -- whitespace (spaces/newlines) is skipped either way, so
 *   the input format (whether N and X are on one line or two) does not matter.
 *
 *   Dry run on:
 *       3
 *       100 30
 *       50 50
 *       7 2
 *   T = 3.
 *     i=0: N=100, X=30  -> prints 70
 *     i=1: N=50,  X=50  -> prints 0
 *     i=2: N=7,   X=2   -> prints 5
 *   Output:
 *       70
 *       0
 *       5
 *
 * COMPLEXITY
 *   Time:  O(T)  -- constant work (one subtraction, one print) per test case.
 *   Space: O(1)  -- three int scalars reused across iterations; nothing stored.
 *
 * EDGE CASES
 *   - X == N            -> prints 0. Handled naturally by subtraction.
 *   - X > N (over-goal) -> prints a NEGATIVE number. If the problem guarantees
 *                          X <= N this never occurs; if it does NOT, and the
 *                          intended answer is "0 remaining", this code is WRONG
 *                          and would need max(0, N - X). DONDRIVE's constraints
 *                          keep X <= N, so plain N - X is safe here -- but flag
 *                          this when revising: it's the one real assumption.
 *   - Overflow          -> if N could exceed ~2*10^9, `int` overflows; use
 *                          `long long`. Fine for this problem's small bounds.
 *   - T == 0            -> loop body never runs, prints nothing. Correct.
 *
 * NOTE (style, not correctness)
 *   `int X` is declared but the only unusual thing is the split reads; there is
 *   no dead code and nothing to fix. `endl` flushes every line -- harmless at
 *   this scale, but `"\n"` would be marginally faster for large T.
 *
 * This solution is already optimal: O(T) time, O(1) space, one arithmetic
 * operation per query -- nothing to improve.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, X;

	cin >> T;

	

	for (int i = 0; i < T; i++){

	    cin >> N;

	    cin >> X;

	    cout << N-X << endl;

	}

	return 0;



}
