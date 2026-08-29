/* ============================================================================
 * CodeChef FOURTICKETS - Four Tickets
 * Difficulty: 302 (Basic Math)
 * ----------------------------------------------------------------------------
 * @platform   CodeChef
 * @id         FOURTICKETS
 * @title      Four Tickets
 * @difficulty 302
 * @topics     Basic Math, Implementation
 * @pattern    Direct arithmetic comparison
 * @url        https://www.codechef.com/problems/FOURTICKETS
 * @solved     2026-06-10
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   Chef wants to buy exactly 4 tickets for his family. Each ticket costs the
 *   same amount, X rupees. Chef has a fixed budget of 1000 rupees. For each of
 *   T test cases, print "YES" if 4 tickets are affordable, otherwise "NO".
 *
 *   Worked example: X = 200 -> total cost = 4 * 200 = 800 <= 1000 -> "YES".
 *                   X = 300 -> total cost = 4 * 300 = 1200 > 1000 -> "NO".
 *
 * INTUITION
 *   The whole decision collapses to one inequality. Buying 4 identical tickets
 *   costs 4 * X. Chef can afford them iff that total does not exceed his budget
 *   of 1000. There is nothing to search or optimize -- it is a single compare.
 *   The reason this is the *complete* answer is that all 4 tickets are forced
 *   (he must buy exactly 4) and priced identically, so no cheaper combination
 *   exists to consider.
 *
 * WALKTHROUGH
 *   - `cin >> T;`            read the number of test cases.
 *   - `for(i = 0; i < T; i++)` loop once per test case.
 *   - `cin >> X;`            read this case's per-ticket price.
 *   - `if(X*4 <= 1000)`      the core check: is the total within budget?
 *       -> true : print "YES"
 *       -> false: print "NO"
 *   - `endl` flushes after each line (fine here; volumes are tiny).
 *
 *   Dry run on input:
 *       T = 3
 *       cases: 250, 250, 260
 *     i=0: X=250 -> 250*4 = 1000, 1000 <= 1000 -> "YES"  (boundary, inclusive)
 *     i=1: X=250 -> same as above                 -> "YES"
 *     i=2: X=260 -> 260*4 = 1040, 1040 > 1000     -> "NO"
 *     Output:
 *       YES
 *       YES
 *       NO
 *
 * COMPLEXITY
 *   Time  : O(T) -- one multiply and one comparison per test case, nothing more.
 *   Space : O(1) -- only the scalars T and X are stored; no arrays or buffers.
 *
 * EDGE CASES
 *   - Exact budget (X = 250, total = 1000): the `<=` makes this "YES". Using
 *     `<` here would be a bug, wrongly rejecting the affordable boundary case.
 *   - Overflow: within typical constraints X is small, so X*4 stays well inside
 *     `int` range. If X could approach INT_MAX/4, promote to long long before
 *     multiplying; as written it is safe for the intended input bounds.
 *   - Non-positive X is not expected per the constraints, but the code still
 *     behaves sensibly (a smaller total only makes "YES" more likely).
 *
 * The solution is already optimal: O(1) work per query, minimal memory, and it
 * handles the inclusive budget boundary correctly. No better approach applies.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    if(X*4 <= 1000){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

	return 0;

}
