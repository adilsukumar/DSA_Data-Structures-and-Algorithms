/* ============================================================================
 * CodeChef - Clear Day
 * Difficulty: 233 (CodeChef rating)
 * ----------------------------------------------------------------------------
 * @platform   CodeChef
 * @id         CLEARDAY
 * @title      Clear Day
 * @difficulty 233
 * @topics     Math, Implementation, Basic Programming
 * @pattern    Constant-time arithmetic (7 - X - Y)
 * @url        https://www.codechef.com/problems/CLEARDAY
 * @solved     2026-06-05
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   A week has exactly 7 days. Over one week it will rain on X of those days
 *   and snow on Y of those days, and these two sets of days never overlap
 *   (a day is rainy, snowy, or clear — never two at once). Report how many
 *   days of the week will be clear.
 *     Example: X = 2 rainy days, Y = 3 snowy days.
 *              Clear days = 7 - 2 - 3 = 2.
 *
 * INTUITION
 *   The week is partitioned into three disjoint buckets: rainy, snowy, clear.
 *   Because they are disjoint and together cover all 7 days, the three counts
 *   must sum to 7:  X + Y + clear = 7.  Solve for the unknown:
 *       clear = 7 - X - Y.
 *   No iteration or simulation is needed — the partition is what makes the
 *   subtraction valid. The guarantee that rainy and snowy days don't overlap
 *   is exactly what lets us subtract both without double-counting.
 *
 * WALKTHROUGH (this code, line by line)
 *   int X, Y;              -> two day-counts.
 *   cin >> X;              -> read X (rainy days).
 *   cin >> Y;              -> read Y (snowy days). (Two reads; could be one
 *                            `cin >> X >> Y;` — behaviour is identical since
 *                            >> skips whitespace/newlines between tokens.)
 *   cout << 7 - X - Y;     -> print the remaining, clear days. Evaluated
 *                            left-to-right: (7 - X) - Y.
 *   Note: `main` returns no explicit value, but C++ implicitly returns 0
 *   from main, so this compiles and exits cleanly. The "your code goes here"
 *   line is a leftover template comment, harmless dead text.
 *
 *   Dry run on X = 4, Y = 1:
 *     read X -> 4
 *     read Y -> 1
 *     7 - X   = 3
 *     3 - Y   = 2
 *     output  -> 2   (two clear days)
 *
 * COMPLEXITY
 *   Time  : O(1) — a fixed number of reads and one arithmetic expression,
 *           independent of the input values.
 *   Space : O(1) — two int variables, no containers.
 *
 * EDGE CASES
 *   - X = 0, Y = 0  -> 7 - 0 - 0 = 7 (whole week clear). Handled correctly.
 *   - X + Y = 7     -> result 0 (no clear days). Handled correctly.
 *   - The subtraction cannot overflow: constraints keep X, Y small (0..7),
 *     well within int range, so no widening to long long is required.
 *   - Trusts the input contract (X + Y <= 7). If given X + Y > 7 it would
 *     print a negative number, but the problem guarantees valid input, so
 *     the code correctly does no defensive clamping.
 *   - Missing note: there is NO multi-test-case loop here. This is fine ONLY
 *     if the problem feeds a single test case. If the judge prepends a T
 *     (number of test cases), this code would read T as X and misbehave —
 *     re-check the constraints section before trusting this on resubmission.
 *
 * OPTIMALITY
 *   This is already optimal: O(1) time and space, the minimum possible for a
 *   problem that must at least read its input. No better approach exists.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int X, Y;

	cin >> X;

	cin >> Y;

	cout << 7 - X - Y;



}
