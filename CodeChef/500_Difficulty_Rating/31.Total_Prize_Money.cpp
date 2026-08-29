/* ==========================================================================
 * CodeChef PRIZEPOOL - Total Prize Money                     Difficulty: 296
 * ==========================================================================
 *
 * @platform   CodeChef
 * @id         PRIZEPOOL
 * @title      Total Prize Money
 * @difficulty 296
 * @topics     Basic Math, Implementation
 * @pattern    O(1) closed-form arithmetic per test
 * @url        https://www.codechef.com/problems/PRIZEPOOL
 * @solved     2026-06-07
 *
 * PROBLEM
 *   For each test case you are given two counts, X and Y, describing how many
 *   winners fall into each of two prize tiers. Every tier-1 winner is paid a
 *   fixed amount of 10 units, and every tier-2 winner is paid a fixed amount
 *   of 90 units. Report the total money paid out.
 *
 *       total = 10 * X  +  90 * Y
 *
 *   (Reconstructed from the code, since 10 and 90 are the only two constants
 *   it uses. If you re-open the statement later, confirm which count is the
 *   "10" tier and which is the "90" tier -- the arithmetic itself is settled.)
 *
 *   Worked example:  X = 2, Y = 3
 *       10*2 + 90*3 = 20 + 270 = 290   -> print 290
 *
 * INTUITION
 *   There is nothing to search or optimize: each winner's payout depends only
 *   on which tier they are in, not on the other winners. So the total is just
 *   a weighted sum of two independent counts. Multiplication distributes over
 *   the group -- pay 10 apiece to X people, 90 apiece to Y people, add them.
 *   The whole task is evaluating one linear expression, which is why it is
 *   O(1) per query and why the "algorithm" is a single formula.
 *
 * WALKTHROUGH (this code, line by line)
 *   int T, X, Y, R;      -- T = number of test cases; X,Y = the two counts;
 *                           R is a scratch variable for the tier-1 subtotal.
 *   cin >> T;            -- read how many test cases follow.
 *   for i in [0, T):     -- process each test case independently.
 *       cin >> X; cin >> Y;   -- read this case's two counts.
 *       R = (X * 10);         -- tier-1 subtotal: 10 units per tier-1 winner.
 *       cout << R + 90*Y      -- add the tier-2 subtotal (90 per winner) and
 *              << endl;         print the grand total, one line per case.
 *   return 0;            -- done.
 *
 *   Dry run on:  T = 1
 *                X = 2, Y = 3
 *     - read T = 1, enter loop with i = 0
 *     - read X = 2, Y = 3
 *     - R = 2 * 10 = 20                 (tier-1 subtotal)
 *     - output R + 90*Y = 20 + 270 = 290
 *     - i becomes 1, loop ends
 *   Output: 290   (matches the worked example above)
 *
 * COMPLEXITY
 *   Time  : O(T). Each test case is a constant number of reads, two
 *           multiplications, and one addition -- no loops over the counts.
 *   Space : O(1). Four scalars reused across every case; nothing is stored.
 *
 * EDGE CASES
 *   - X = 0 or Y = 0: that tier contributes 0 naturally (10*0 or 90*0),
 *     so an all-tier-1 or all-tier-2 case is handled with no special code.
 *   - Both zero: prints 0, which is correct.
 *   - Integer overflow: R and the printed value are plain `int`, which caps
 *     out near 2.1e9. The formula stays safe as long as 10*X + 90*Y fits --
 *     e.g. X,Y up to ~1e6 gives at most ~9e7, comfortably inside int. If the
 *     real constraints allow X or Y beyond ~2e7, switch X, Y, R (and print)
 *     to `long long` to avoid silent wraparound. Worth double-checking the
 *     stated bounds against this.
 *
 * NOTE (already optimal; no better algorithm exists)
 *   The math is a closed form, so nothing beats O(1) per case. One tiny I/O
 *   nit for large T: `endl` flushes the stream every line. Using '\n' plus a
 *   single flush at exit (or cin/cout sync off) trims constant overhead --
 *   irrelevant for this problem's size, but a good reflex to remember.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y, R;

	cin >> T;

	

	for (int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    R = (X*10);

	    cout << R + 90*Y << endl;

	}

    return 0;

}
