/* ============================================================================
 * CodeChef PUZHUNT - Puzzle Hunt
 * Difficulty: 279 (very easy)
 * ----------------------------------------------------------------------------
 * @platform   CodeChef
 * @id         PUZHUNT
 * @title      Puzzle Hunt
 * @difficulty 279
 * @topics     Conditional Statements, Implementation
 * @pattern    Range Check with if/else
 * @url        https://www.codechef.com/problems/PUZHUNT
 * @solved     2026-06-07
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   You are given a single integer N (a count of participants, hours, or
 *   similar, depending on the story). A condition is satisfied only when N
 *   lies within an inclusive range -- here, when 6 <= N <= 8. Print "Yes"
 *   if N falls inside that window, otherwise print "No".
 *
 *   Worked example:
 *       N = 7  -> "Yes"   (7 is between 6 and 8 inclusive)
 *       N = 5  -> "No"    (5 is below the lower bound)
 *       N = 9  -> "No"    (9 is above the upper bound)
 *
 * INTUITION
 *   The entire task is a membership test on a closed interval. A value is
 *   inside [6, 8] exactly when it is simultaneously >= 6 AND <= 8. Those two
 *   comparisons, joined by &&, fully characterise the interval -- no loop,
 *   no data structure, no arithmetic is needed. WHY it works: the integers
 *   satisfying both bounds are precisely {6, 7, 8}, which is the answer set,
 *   so the boolean expression is equivalent to "N is one of the accepted
 *   values". Everything else lands in the else branch.
 *
 * WALKTHROUGH (this code, line by line)
 *   - `int N; cin >> N;`      read the single integer from standard input.
 *   - `if (N >= 6 && N <= 8)` the range check. Both operands must be true;
 *                             `&&` short-circuits, but correctness does not
 *                             depend on that here.
 *   - `cout << "Yes";`        taken only when N is in {6, 7, 8}.
 *   - `else { cout << "No"; }` taken for every other integer.
 *   Note: nothing is printed after the word -- no trailing '\n'. CodeChef's
 *   checker for this style of problem accepts the answer without a newline,
 *   so this is fine, though `<< "Yes\n"` would be tidier.
 *
 *   Dry run on N = 8:
 *       read N            -> N = 8
 *       evaluate N >= 6   -> 8 >= 6  -> true
 *       evaluate N <= 8   -> 8 <= 8  -> true   (boundary case, still inside)
 *       true && true      -> true    -> enter the if branch
 *       output            -> "Yes"
 *
 *   Dry run on N = 6 (the other boundary):
 *       N >= 6 -> true, N <= 8 -> true -> "Yes"   (lower edge included)
 *
 *   Dry run on N = 10:
 *       N >= 6 -> true, N <= 8 -> false -> false -> else branch -> "No"
 *
 * COMPLEXITY
 *   Time  : O(1)  -- one read and at most two integer comparisons, no loops.
 *   Space : O(1)  -- a single int; no allocation that scales with input.
 *
 * EDGE CASES
 *   - Boundaries 6 and 8: both are included because the comparisons are
 *     `>=` and `<=` (inclusive), not strict `>`/`<`. Verified above.
 *   - Just outside (5 and 9): correctly rejected, since exactly one bound
 *     fails and `&&` requires both.
 *   - Negative or zero N: fall in the else branch -> "No", as expected.
 *   - Very large N (near INT_MAX): still fits in `int`; comparison is safe.
 *     Only a value exceeding int range would break the read, but the
 *     constraints keep N small, so this cannot occur.
 *
 * This solution is already optimal: the answer is a constant-time predicate
 * on a fixed interval, so no better time or space complexity exists.
 * ============================================================================ */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int N;

	cin >> N;

	if(N >= 6 && N <= 8){

	    cout << "Yes";

	}

	else{

	    cout << "No";

	}



}
