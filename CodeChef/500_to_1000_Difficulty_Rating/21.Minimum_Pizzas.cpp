/* ============================================================================
 * CodeChef MINPIZZA - Minimum Pizzas
 * Difficulty: 546 (Beginner / Basic Math)
 * ----------------------------------------------------------------------------
 * @platform   CodeChef
 * @id         MINPIZZA
 * @title      Minimum Pizzas
 * @difficulty 546
 * @topics     Basic Math, Implementation
 * @pattern    Integer Ceiling Division
 * @url        https://www.codechef.com/problems/MINPIZZA
 * @solved     2026-06-10
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   There are N people and each person wants exactly X slices of pizza. Every
 *   pizza is cut into 4 slices. Find the minimum number of WHOLE pizzas that
 *   must be ordered so everyone gets their X slices (leftover slices are fine).
 *   Answer each of T independent test cases.
 *
 *   Example: N = 3 people, X = 5 slices each -> 15 slices needed.
 *            Each pizza gives 4 slices. 15 / 4 = 3.75, so 3 pizzas (12 slices)
 *            are not enough; you must round UP to 4 pizzas (16 slices). -> 4.
 *
 * INTUITION
 *   Total slices required = N * X. Since a pizza is indivisible and yields 4
 *   slices, the answer is ceil(N*X / 4) -- you can never buy a fraction of a
 *   pizza, so any remaining slice-demand forces one more whole pizza.
 *
 *   The classic trick for ceiling division of non-negative integers WITHOUT
 *   floating point is:
 *       ceil(a / b) == (a + b - 1) / b        // using integer (floor) division
 *   Here b = 4, so (a + 3) / 4. This is exactly what the code computes:
 *   (N*X + 3) / 4. It works because adding (b-1) pushes any nonzero remainder
 *   up past the next multiple of b, while an exact multiple (remainder 0) is
 *   left in the same bucket. Floating point (e.g. ceil((double)N*X/4)) is
 *   avoided on purpose -- it can mis-round on large values.
 *
 * WALKTHROUGH  (line by line)
 *   - Read T, the number of test cases.
 *   - Loop T times. Each iteration reads N then X on their own cin extractions
 *     (they may be on the same line or different lines; >> skips whitespace).
 *   - Compute (N*X + 3) / 4 with integer division and print it, one per line.
 *   Note there is no separate `slices` variable; N*X is computed inline. The
 *   "// your code goes here" is leftover boilerplate (dead comment), harmless.
 *
 *   Dry run on N=3, X=5:
 *     N*X          = 15
 *     N*X + 3      = 18
 *     18 / 4       = 4   (integer division truncates 4.5 -> 4)
 *     print 4                                            <-- matches example
 *
 *   Dry run on an exact multiple, N=2, X=6:
 *     N*X          = 12   (already a multiple of 4)
 *     12 + 3       = 15
 *     15 / 4       = 3    (the +3 did NOT bump it up -- correct, 3 pizzas)
 *     print 3
 *
 * COMPLEXITY
 *   Time  : O(T) -- constant work (one multiply, add, divide) per test case.
 *   Space : O(1) -- only a handful of scalar ints regardless of input size.
 *
 * EDGE CASES
 *   - Exact multiples of 4 (N*X % 4 == 0): the +3 stays below the next
 *     multiple, so no spurious extra pizza. Handled correctly (see dry run 2).
 *   - X = 0 (nobody wants slices): N*X = 0 -> (0+3)/4 = 0 pizzas. Correct.
 *   - INTEGER OVERFLOW (the real risk): N*X is computed in `int`. If the
 *     constraints allow N and X large enough that N*X exceeds ~2.1e9, this
 *     silently overflows and prints garbage. For this easy problem the limits
 *     are small so `int` passes, but the safe habit is `long long`:
 *         cout << (1LL * N * X + 3) / 4 << "\n";
 *   - `endl` flushes the stream every line; for large T prefer '\n' for speed.
 *     Not a correctness issue here, just a minor performance note.
 *
 * This solution is already optimal in time and space (O(1) per query, exact
 * integer arithmetic). The only production hardening worth making is widening
 * to long long to defend against overflow and using '\n' instead of endl.
 * ============================================================================ */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N;

	    cin >> X;

	    cout << (N*X+3) / 4 << endl; 

	}

	return 0;

}
