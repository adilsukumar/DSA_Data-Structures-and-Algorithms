/* ============================================================================
 * CodeChef OFFICE - Chef In His Office
 * Difficulty: 532 (Beginner)  |  Basic Programming, Math
 * ----------------------------------------------------------------------------
 * @platform   CodeChef
 * @id         OFFICE
 * @title      Chef In His Office
 * @difficulty 532
 * @topics     Basic Programming, Math, Implementation
 * @pattern    Direct arithmetic formula, O(1)
 * @url        https://www.codechef.com/problems/OFFICE
 * @solved     2026-06-09
 * ============================================================================
 *
 * PROBLEM
 *   For each of T independent test cases you are given two integers X and Y,
 *   and must print a single derived value. This code's answer is exactly:
 *
 *          result = 4 * X + Y
 *
 *   i.e. each of the X units contributes a fixed weight of 4, and Y is added
 *   on top as a flat term. (The narrative framing on the CodeChef page maps
 *   X and Y onto this "four-per-unit plus a bonus" arithmetic; I could not
 *   re-fetch the exact wording here, but the computation the code performs is
 *   unambiguous and is what you'll be graded against.)
 *
 *   Example: X = 3, Y = 5  ->  4*3 + 5 = 17.
 *
 * INTUITION
 *   There is nothing to search or sort. The answer is a closed-form linear
 *   expression in the two inputs, so the entire task is: read the pair, plug
 *   into 4*X + Y, print. It works because the mapping from (X, Y) to the
 *   answer is a fixed formula with no branching and no dependence on other
 *   test cases -- every case is fully independent.
 *
 * WALKTHROUGH  (of this code)
 *   1. `cin >> T;`                 read the number of test cases.
 *   2. `for i in [0, T)`           loop once per case; the counter i is only
 *                                  a repeat count and is never used in math.
 *   3. `cin >> X; cin >> Y;`       read the two integers for this case (two
 *                                  separate extractions -- same as one line;
 *                                  whitespace/newlines are skipped by >>).
 *   4. `cout << X*4 + Y << endl;`  evaluate 4*X + Y and print, one line each.
 *
 *   Dry run on:
 *       T = 2
 *       3 5
 *       1 0
 *
 *     iter i=0: X=3, Y=5 -> X*4=12, +Y=17            prints "17"
 *     iter i=1: X=1, Y=0 -> X*4=4,  +0 =4            prints "4"
 *   Output:
 *       17
 *       4
 *
 * COMPLEXITY
 *   Time  : O(T) overall, O(1) per test case -- one multiply and one add.
 *   Space : O(1) -- three scalar ints reused across iterations, no buffers.
 *
 * EDGE CASES
 *   - Multiple test cases: handled by the T-loop; each case is self-contained
 *     so nothing leaks between iterations (X and Y are overwritten each time).
 *   - X = 0 or Y = 0: formula degrades cleanly to Y or 4*X respectively.
 *   - INTEGER OVERFLOW (the real risk): X, Y, and the product 4*X are all
 *     computed in `int`. If the constraints allow X beyond ~5.3e8, then 4*X
 *     wraps around a 32-bit int and the answer is silently wrong. For the
 *     small bounds typical of a 532-rated problem this is fine, but if you
 *     revisit this and the limits are large, switch X/Y/result to `long long`
 *     (and read/print accordingly). This is the one thing that could break it.
 *   - `endl` flushes the stream every line; harmless at this scale, but for
 *     high-T problems prefer '\n' plus a single flush at the end.
 *
 * NOTE
 *   The `int i` counter and the "your code goes here" template comment are
 *   inert boilerplate -- i drives only the loop count.
 *
 * This solution is already optimal: O(1) per query is the theoretical floor
 * for a fixed arithmetic formula, so there is no better approach to sketch.
 * The only hardening worth making is the 64-bit widening noted above.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    cout << X*4 + Y << endl;

	}

	return 0;

}
