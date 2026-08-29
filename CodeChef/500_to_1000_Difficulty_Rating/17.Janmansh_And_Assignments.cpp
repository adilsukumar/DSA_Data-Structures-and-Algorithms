/*
 * ============================================================================
 * CodeChef JASSIGNMENTS - Janmansh and Assignments        Difficulty: 513
 * ============================================================================
 *   @platform   CodeChef
 *   @id         JASSIGNMENTS
 *   @title      Janmansh and Assignments
 *   @difficulty 513
 *   @topics     Implementation, Conditionals, Basic Programming
 *   @pattern    Threshold Comparison (X vs 7)
 *   @url        https://www.codechef.com/problems/JASSIGNMENTS
 *   @solved     2026-06-08
 *
 * ----------------------------------------------------------------------------
 * PROBLEM
 * ----------------------------------------------------------------------------
 *   Janmansh must finish X assignments. He can complete at most one assignment
 *   per day, and a week has 7 days. For each of T test cases, decide whether he
 *   can finish everything within a single week: print "Yes" if it is possible,
 *   otherwise "No".
 *
 *   Worked example:
 *     X = 5  -> 5 assignments fit inside 7 days          -> "Yes"
 *     X = 7  -> exactly one per day, all 7 days used     -> "Yes"
 *     X = 8  -> 8 assignments need 8 days, only 7 exist  -> "No"
 *
 * ----------------------------------------------------------------------------
 * INTUITION
 * ----------------------------------------------------------------------------
 *   "One assignment per day, seven days" collapses to a single capacity number:
 *   7. The maximum work achievable in a week is exactly 7 assignments, so the
 *   whole question reduces to "is X <= 7?". No loop over days, no arithmetic on
 *   rates -- the answer is a single comparison against the constant 7. It works
 *   because the per-day limit is 1, which makes days-needed == X, and a week is
 *   feasible precisely when days-needed does not exceed the 7 available days.
 *
 * ----------------------------------------------------------------------------
 * WALKTHROUGH
 * ----------------------------------------------------------------------------
 *   cin >> T;                 read the number of test cases.
 *   for i in 0..T-1:          process each test case independently.
 *       cin >> X;             read this case's assignment count.
 *       if (X > 7)            more assignments than the 7-day capacity...
 *           print "No";       ...cannot fit in a week.
 *       else                  X <= 7 (note: X == 7 lands here, correctly Yes)...
 *           print "Yes";      ...fits.
 *   endl flushes each line; harmless for these tiny outputs.
 *
 *   The boundary lives in the operator choice: `X > 7` (strict) sends 8+ to
 *   "No" and keeps 7 in the "Yes" branch -- exactly the intended cutoff. Using
 *   `>=` here would be the classic off-by-one bug; this code avoids it.
 *
 *   Dry run on input:  T=3, then X = 7, 8, 1
 *     iter 0: X=7 -> 7 > 7 is false -> else -> "Yes"
 *     iter 1: X=8 -> 8 > 7 is true  -> if   -> "No"
 *     iter 2: X=1 -> 1 > 7 is false -> else -> "Yes"
 *   Output:
 *     Yes
 *     No
 *     Yes
 *
 * ----------------------------------------------------------------------------
 * COMPLEXITY
 * ----------------------------------------------------------------------------
 *   Time:  O(T)  -- one read and one comparison per test case, nothing nested.
 *   Space: O(1)  -- only the scalars T, X, i are kept; no arrays or buffers.
 *
 * ----------------------------------------------------------------------------
 * EDGE CASES
 * ----------------------------------------------------------------------------
 *   - X == 7 exactly: the strict `>` keeps this in the "Yes" branch (a full
 *     week is enough), which is the correct and easiest case to get wrong.
 *   - X == 8: the first "No" value; handled by the strict comparison.
 *   - Large T: only bounded by input size since work per case is constant.
 *   - Assumes X is a positive integer within int range, per the constraints; no
 *     validation is done, which is fine given the problem's guarantees.
 *   - `main` has no explicit `return 0;`, but C++ implicitly returns 0 from
 *     main, so this is not a bug -- just a stylistic omission. The leftover
 *     "// your code goes here" is dead template noise and can be deleted.
 *
 *   This solution is already optimal: the answer is a single O(1) comparison
 *   per case, and O(T) total is unavoidable since every X must be read.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T,X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    if(X > 7){

	        cout << "No" << endl;

	    }

	    else{

	        cout << "Yes" << endl;

	    }

	}



}
