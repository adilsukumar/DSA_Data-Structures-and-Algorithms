/*
 * ============================================================================
 * CodeChef AUDIBLE - Audible Range                                Difficulty 279
 * ============================================================================
 *
 * @platform   CodeChef
 * @id         AUDIBLE
 * @title      Audible Range
 * @difficulty 279
 * @topics     Basic Math, Implementation
 * @pattern    Range Membership Check
 * @url        https://www.codechef.com/problems/AUDIBLE
 * @solved     2026-06-07
 *
 * ----------------------------------------------------------------------------
 * PROBLEM
 * ----------------------------------------------------------------------------
 *   The audible range (here, the frequencies a dog can hear) spans 67 Hz to
 *   45000 Hz inclusive. For each of T test cases you are given a frequency X;
 *   print "YES" if the sound is audible (67 <= X <= 45000) and "NO" otherwise.
 *
 *   Worked example:
 *       T = 3
 *       X = 66     -> 66  < 67          -> NO
 *       X = 67     -> on the lower edge -> YES
 *       X = 50000  -> 50000 > 45000     -> NO
 *
 * ----------------------------------------------------------------------------
 * INTUITION
 * ----------------------------------------------------------------------------
 *   There is no algorithm to design here -- the whole task is a definition
 *   lookup. "Inside a closed interval [lo, hi]" is exactly the compound
 *   condition (X >= lo && X <= hi). Both comparisons must hold simultaneously,
 *   so they are joined with && rather than checked separately. The bounds are
 *   inclusive, which is why the operators are >= and <= (not > and <): a value
 *   sitting on either endpoint still counts as audible.
 *
 *   Why this is correct and not merely "close": a single comparison would only
 *   fence off one side (e.g. X >= 67 alone would wrongly accept 1000000).
 *   Requiring both sides pinned is the complete and minimal test for interval
 *   membership.
 *
 * ----------------------------------------------------------------------------
 * WALKTHROUGH (this code)
 * ----------------------------------------------------------------------------
 *   cin >> T;                      read the number of test cases.
 *   for (i = 0; i < T; i++)        loop once per query; i is just a counter and
 *                                  is never used inside the body -- fine here.
 *     cin >> X;                    read this query's frequency into X (reused
 *                                  each iteration; no need to store history).
 *     if (X >= 67 && X <= 45000)   the closed-interval membership test.
 *       cout << "YES" << endl;     audible.
 *     else
 *       cout << "NO"  << endl;     out of range on one side or the other.
 *
 *   Note: `endl` flushes the output buffer on every line. For this constraint
 *   size it is harmless, but "\n" would be marginally faster (see below).
 *
 *   Dry run on T=3, X = [66, 67, 50000]:
 *       iter 0: X=66     -> 66>=67 is false -> && short-circuits -> NO
 *       iter 1: X=67     -> 67>=67 true, 67<=45000 true          -> YES
 *       iter 2: X=50000  -> 50000>=67 true, 50000<=45000 false   -> NO
 *   Output:
 *       NO
 *       YES
 *       NO
 *
 * ----------------------------------------------------------------------------
 * COMPLEXITY
 * ----------------------------------------------------------------------------
 *   Time  : O(T)  -- one read and two constant-time comparisons per test case.
 *   Space : O(1)  -- only the scalars T, X, i; nothing scales with input size.
 *
 * ----------------------------------------------------------------------------
 * EDGE CASES
 * ----------------------------------------------------------------------------
 *   - Exact endpoints 67 and 45000: accepted, because the operators are
 *     inclusive (>=, <=). This is the classic off-by-one trap and the code
 *     gets it right.
 *   - Just outside (66, 45001): correctly rejected.
 *   - int range: X fits comfortably in a 32-bit int for the stated bounds, so
 *     there is no overflow concern. If the judge ever fed a value beyond ~2.1e9
 *     it would overflow int, but that is far outside this problem's domain.
 *   - Negative or zero X: handled naturally -- they fail X >= 67 and print NO.
 *
 * ----------------------------------------------------------------------------
 * OPTIMALITY
 * ----------------------------------------------------------------------------
 *   This is already optimal: O(T) time and O(1) space are the theoretical
 *   floor, since every input must be read at least once. No better approach
 *   exists. The only micro-tweak (not a correctness or complexity issue) is
 *   dropping `endl` for "\n" and adding a fast-IO line to avoid per-line
 *   flushing:
 *
 *       ios_base::sync_with_stdio(false); cin.tie(nullptr);
 *       cout << (X >= 67 && X <= 45000 ? "YES" : "NO") << "\n";
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	for (int i = 0; i < T; i++){

	    cin >> X;

	    if (X >= 67 && X <= 45000){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

	return 0;

}
