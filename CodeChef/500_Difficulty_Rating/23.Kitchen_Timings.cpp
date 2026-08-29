/*
 * ============================================================================
 * CodeChef KITCHENTIME - Kitchen Timings          Difficulty: 273 (Basic Math)
 * ============================================================================
 *   @platform   CodeChef
 *   @id         KITCHENTIME
 *   @title      Kitchen Timings
 *   @difficulty 273
 *   @topics     Basic Math, Implementation
 *   @pattern    Per-query subtraction (Y - X)
 *   @url        https://www.codechef.com/problems/KITCHENTIME
 *   @solved     2026-06-06
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   There are T independent test cases. Each gives two integers X and Y, where
 *   X is a start time and Y is an end time. For every test case, report how
 *   long the interval lasts, i.e. the elapsed duration Y - X.
 *
 *   Worked example:
 *     T = 2
 *     Case 1: X = 3, Y = 10  ->  10 - 3 = 7
 *     Case 2: X = 0, Y = 5   ->   5 - 0 = 5
 *   Output:
 *     7
 *     5
 *
 * INTUITION
 *   The duration between two points on a single timeline is just the end minus
 *   the start. There is no wraparound, no clock arithmetic, no accumulation
 *   across cases — each case is fully answered by one subtraction. It works
 *   because the problem guarantees Y is the later time, so Y - X is the gap
 *   between them and is non-negative. The only real "algorithm" here is reading
 *   input correctly and printing one answer per line.
 *
 * WALKTHROUGH  (line by line, then a dry run)
 *   - `cin >> T;`            read the number of test cases.
 *   - `for (i = 0..T-1)`     loop once per case; the counter i is only used to
 *                            bound the loop, never in the math (correct — the
 *                            cases are independent).
 *   - `cin >> X; cin >> Y;`  read the two integers for this case. Splitting the
 *                            reads onto two statements is stylistically loose
 *                            but behaves identically to `cin >> X >> Y;`
 *                            because `>>` skips whitespace/newlines the same way.
 *   - `cout << Y - X << endl;` print the elapsed time and flush the line.
 *
 *   Dry run on the example above (T = 2):
 *     read T=2
 *     i=0: read X=3, Y=10 -> print 10-3 = 7
 *     i=1: read X=0, Y=5  -> print  5-0 = 5
 *     loop ends, return 0. Output is "7\n5\n". Matches.
 *
 *   Note on `int`: X, Y, and Y-X are all held in `int`. This is safe only while
 *   the values fit in a 32-bit signed int (roughly +/- 2.1e9). For this rating
 *   of problem that is fine, but see EDGE CASES.
 *
 * COMPLEXITY
 *   Time:  O(T) — a constant amount of work (two reads, one subtraction, one
 *          print) per test case, so total work scales linearly with T.
 *   Space: O(1) — only the scalars T, X, Y are stored; nothing grows with input.
 *
 * EDGE CASES
 *   - X == Y: prints 0, the correct zero-length duration.
 *   - Y < X (if the problem ever allowed it): this would print a negative number.
 *     The code does no abs() or clamping, so it trusts the guarantee Y >= X.
 *     If that guarantee is not stated, this is a latent bug.
 *   - Very large magnitudes: if X or Y can exceed ~2.1e9, `int` overflows and
 *     the result is garbage; `long long` would be the safe choice. As written,
 *     the code assumes 32-bit range.
 *   - T == 0: the loop body never runs and nothing is printed — correct.
 *   - `endl` flushes on every line. For large T this is slower than '\n'; not a
 *     correctness issue, just avoidable I/O overhead.
 *
 * OPTIMALITY
 *   This is already optimal in the algorithmic sense: each answer is a single
 *   O(1) subtraction and you cannot do better than reading each case once. The
 *   only refinements are cosmetic / defensive, e.g.:
 *
 *     long long X, Y;                 // avoid overflow on large inputs
 *     cin >> X >> Y;                  // single combined read
 *     cout << (Y - X) << '\n';        // '\n' instead of endl (skip flushing)
 *
 *   No change to the core logic is warranted.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	for (int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    cout << Y-X << endl;

	}

	return 0;



}
