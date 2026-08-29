/* ============================================================================
 * CodeChef DETSCORE - Determine The Score                    Difficulty: 267
 * ----------------------------------------------------------------------------
 * @platform   CodeChef
 * @id         DETSCORE
 * @title      Determine The Score
 * @difficulty 267
 * @topics     Basic Programming Concepts, Basic Math
 * @pattern    Integer Division then Multiply
 * @url        https://www.codechef.com/problems/DETSCORE
 * @solved     2026-06-05
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   A group of X students each solved N problems. Every group earns a fixed
 *   reward of 10 points for each *group of 10 students*, and the total score
 *   is that per-group reward multiplied by the number of problems solved.
 *   Concretely: with TG = 10, the answer for each test is (X / 10) * N, using
 *   INTEGER division (any remainder of students below a full group of 10 is
 *   discarded). For T test cases, each supplies X then N; print one answer per
 *   line.
 *     Example: X = 25, N = 4  ->  (25 / 10) * 4 = 2 * 4 = 8.
 *              X = 9,  N = 7  ->  (9  / 10) * 7 = 0 * 7 = 0.
 *
 * INTUITION
 *   The whole task is a single arithmetic expression, so the only real
 *   decision is the ORDER of operations. The code divides FIRST ((X/TG)*N),
 *   which is exactly right: it counts how many complete groups of 10 exist,
 *   then scales by N. Doing division first deliberately floors away the
 *   leftover < 10 students, which matches the "complete group" semantics.
 *   Note this is NOT algebraically equal to X*N/10 in integer math: for
 *   X = 25, N = 4 the code gives (25/10)*4 = 8, whereas X*N/10 = 100/10 = 10.
 *   The two disagree whenever X is not a multiple of 10, so the grouping
 *   order chosen here is a meaningful, correct choice -- not an accident.
 *
 * WALKTHROUGH
 *   - `int TG = 10;`     the group size, the divisor, set once up front.
 *   - `cin >> T;`        read the number of test cases.
 *   - `for i in 0..T-1`  loop once per test case.
 *       - `cin >> X;`    number of students.
 *       - `cin >> N;`    number of problems solved.
 *       - `cout << (X/TG) * N << endl;`
 *                        integer-divide X by 10 to get full groups, multiply
 *                        by N, print, newline.
 *   - `int i` is the loop counter only; the declared-but-unused pattern here
 *     is fine. There is no accumulation between tests -- each answer is
 *     independent, so no state needs resetting.
 *
 *   Dry run on input:
 *       2          <- T = 2
 *       25 4       <- test 1: X = 25, N = 4
 *       9 7        <- test 2: X = 9,  N = 7
 *     Test 1: X/TG = 25/10 = 2 (floor), 2*N = 2*4 = 8   -> prints 8
 *     Test 2: X/TG = 9/10  = 0 (floor), 0*N = 0*7 = 0   -> prints 0
 *     Output:
 *       8
 *       0
 *
 * COMPLEXITY
 *   Time  : O(T) -- constant work (one divide, one multiply) per test case.
 *   Space : O(1) -- four ints reused across every iteration; nothing stored.
 *
 * EDGE CASES
 *   - X < 10           -> X/10 = 0, so the score is 0. Handled naturally by
 *                         integer division; no special case needed.
 *   - N = 0            -> product is 0 regardless of X. Fine.
 *   - X exact multiple -> e.g. X = 30 gives 3*N, no remainder lost. Fine.
 *   - Overflow risk    -> answer is (X/10)*N. If both X and N approach the
 *                         int limit this can overflow a 32-bit int; for this
 *                         problem's small constraints it is safe, but a
 *                         `long long` result would be the defensive choice if
 *                         limits were larger.
 *
 * This solution is already optimal: the answer is a closed-form O(1)
 * expression per test with correct operation ordering. No better approach
 * exists.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int TG, T, X, N;

	TG = 10;

	cin >> T;

	for(int i = 0; i < T; i++){

	    cin >> X;

	    cin >> N;

	    cout << (X/TG) * N << endl;

	}

	return 0;

}
