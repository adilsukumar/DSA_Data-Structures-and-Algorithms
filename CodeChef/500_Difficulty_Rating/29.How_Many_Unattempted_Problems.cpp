/* ============================================================================
 * CodeChef PRACLIST - How Many Unattempted Problems
 * Difficulty: 264 (very easy / beginner)
 * ----------------------------------------------------------------------------
 * @platform   CodeChef
 * @id         PRACLIST
 * @title      How Many Unattempted Problems
 * @difficulty 264
 * @topics     Basic Programming, Implementation, Math
 * @pattern    Single Subtraction
 * @url        https://www.codechef.com/problems/PRACLIST
 * @solved     2026-06-05
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   A practice list contains X problems in total. You have already attempted Y
 *   of them. Report how many problems are still unattempted.
 *   The answer is simply the leftovers: X - Y.
 *
 *   Worked example:  X = 10 problems, Y = 4 attempted  ->  10 - 4 = 6 unattempted.
 *
 * INTUITION
 *   Every problem is in exactly one of two buckets: attempted or not. The two
 *   buckets partition the whole list, so |unattempted| = |total| - |attempted|.
 *   There is no overlap and nothing outside the list, which is WHY a single
 *   subtraction is both correct and complete -- no counting, looping, or
 *   condition-checking is needed.
 *
 * WALKTHROUGH (this code, line by line)
 *   - `int X, Y;`            declare total (X) and attempted (Y).
 *   - `cin >> X;`            read the total problem count.
 *   - `cin >> Y;`            read the attempted count.
 *                            (Two separate `cin >>` here behave identically to
 *                             `cin >> X >> Y;` -- whitespace/newlines are skipped
 *                             either way, so the input format doesn't matter.)
 *   - `cout << X-Y;`         print the difference = the unattempted count.
 *   - `return 0;`            signal success.
 *
 *   Dry run on input "10 4":
 *     read X -> X = 10
 *     read Y -> Y = 4
 *     X - Y  -> 6
 *     output: 6
 *
 * COMPLEXITY
 *   Time:  O(1) -- a fixed amount of I/O and one arithmetic operation, no loops.
 *   Space: O(1) -- just the two integers X and Y.
 *
 * EDGE CASES
 *   - Y == X (attempted everything): prints 0. Correct.
 *   - Y == 0 (attempted nothing):    prints X. Correct.
 *   - Overflow: safe as long as X fits in `int` (< ~2.1e9). Given the beginner
 *     rating the constraints are tiny, so `int` is fine; if constraints were
 *     large you'd switch to `long long`.
 *   - Y > X would give a negative answer, but the problem guarantees Y <= X,
 *     so this input never occurs -- the code does not (and need not) guard it.
 *   - No trailing newline is printed. CodeChef accepts this; add "\n" only if a
 *     judge is strict about it.
 *
 * This solution is already optimal (constant time and space); nothing to improve.
 * ============================================================================ */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int X, Y;

	cin >> X;

	cin >> Y;

	cout << X-Y;

	return 0;



}
