/* ============================================================================
 * CodeChef CHAIRS_ - Chairs Requirement
 * Difficulty: 305 (Basic Math / Implementation)
 * ----------------------------------------------------------------------------
 * @platform   CodeChef
 * @id         CHAIRS_
 * @title      Chairs Requirement
 * @difficulty 305
 * @topics     Basic Math, Implementation
 * @pattern    Clamped Difference max(X-Y, 0)
 * @url        https://www.codechef.com/problems/CHAIRS_
 * @solved     2026-06-12
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   For each of T independent test cases you are given two integers on a line:
 *   X = the number of chairs you currently have, and Y = the number of chairs
 *   actually needed. Report the SURPLUS: how many chairs are left over once the
 *   requirement is met. If you already have as many or more than needed, the
 *   surplus is X - Y; if you are short, there is no surplus, so the answer is 0.
 *   (The task asks only for the leftover count, not the shortage.)
 *
 *   Example:  X = 7, Y = 4  -> 3 chairs to spare.
 *             X = 2, Y = 5  -> you are short, surplus is 0.
 *             X = 5, Y = 5  -> exactly enough, surplus is 0.
 *
 * INTUITION
 *   The whole task is a single expression: max(X - Y, 0). We never care by how
 *   much we fall short, only whether a surplus exists and how big it is. Clamping
 *   the difference at 0 is what encodes "shortages don't produce negative output."
 *   WHY it works: X >= Y is exactly the condition under which X - Y is >= 0, so
 *   the branch and the clamp are the same statement written two ways. There is no
 *   accumulation or state carried between test cases, so each line is solved in
 *   isolation.
 *
 * WALKTHROUGH
 *   - `cin >> T;`                 read how many test cases follow.
 *   - `for (i = 0; i < T; i++)`   loop once per test case; i is only a counter.
 *   - `cin >> X; cin >> Y;`       read the two integers for this case.
 *   - `if (X >= Y)`               surplus branch: there are at least as many
 *         `cout << X - Y`         chairs as needed, so print the leftover count.
 *   - `else cout << 0`            shortage/exact branch: nothing to spare -> 0.
 *         (X == Y also lands in the first branch and correctly prints 0.)
 *   - `endl`                      terminates each answer with a newline.
 *
 *   Dry run on T = 3 with lines (7 4), (2 5), (5 5):
 *     case 1: X=7 Y=4 -> 7>=4 true  -> print 7-4 = 3
 *     case 2: X=2 Y=5 -> 2>=5 false -> print 0
 *     case 3: X=5 Y=5 -> 5>=5 true  -> print 5-5 = 0
 *   Output, one per line:  3 / 0 / 0.  Notice cases 2 and 3 both yield 0 via
 *   different branches, confirming the boundary X == Y is handled.
 *
 * COMPLEXITY
 *   Time:  O(T) overall -- constant work (one compare, one subtraction, one
 *          print) per test case, so it scales linearly in the number of cases.
 *   Space: O(1) -- only the scalars T, X, Y are kept; nothing is stored per case.
 *
 * EDGE CASES
 *   - X == Y: falls into the `>=` branch and prints X-Y = 0 (correct, no surplus).
 *   - X <  Y: the else branch prints 0 rather than a negative number -- this is
 *     the clamp that keeps a shortage from leaking a negative value.
 *   - Large values: X-Y stays within `int` for the stated constraints; if the
 *     problem ever allowed values near 2^31 the subtraction is still safe here
 *     because X >= Y is guaranteed before subtracting (no negative overflow).
 *   - Minor style note (not a bug): `endl` flushes the output buffer every line.
 *     For very large T, `"\n"` is faster; the logic is unaffected either way.
 *
 * This solution is already optimal: O(1) per test case and O(1) memory, which
 * cannot be improved for a per-case arithmetic answer.
 * ==========================================================================*/

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    if(X>=Y){

	        cout << X-Y << endl;

	    }

	    else{

	        cout << 0 << endl;

	    }

	}

    return 0;

}
