/* ============================================================================
 * CodeChef EXAMCHEF - Exams            Difficulty: 519 (easy / "notsoloud")
 * ----------------------------------------------------------------------------
 * @platform   CodeChef
 * @id         EXAMCHEF
 * @title      Exams
 * @difficulty 519
 * @topics     Math, Implementation
 * @pattern    Half-of-total threshold check
 * @url        https://www.codechef.com/problems/EXAMCHEF
 * @solved     2026-06-09
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   For each test case you are given three integers X, Y, Z. The exam's
 *   maximum obtainable score is X * Y (read it as X items each worth Y marks).
 *   Chef actually scored Z. Chef PASSES only if his score is strictly more
 *   than half of the maximum, i.e. Z > (X*Y)/2. Print "YES" if he passes,
 *   otherwise "NO".
 *
 *   NOTE (honesty): I could not re-open the official statement in this
 *   session, so the exact "pass / X-Y-Z labelling" wording above is inferred
 *   from what the code computes. The arithmetic itself is not in doubt: the
 *   program prints YES exactly when (X*Y)/2 < Z under integer division.
 *
 *   Example: X=4, Y=5 -> maximum = 20, half = 10. If Z=11 -> 10 < 11 -> YES.
 *            If Z=10 -> 10 < 10 is false -> NO (exactly half is not enough).
 *
 * INTUITION
 *   "More than half of the total" is the whole problem. Total is X*Y, so the
 *   bar to clear is (X*Y)/2, and the single test Z > bar decides everything.
 *   There is nothing to search or iterate over per case - it is one product,
 *   one halving, one comparison. Why it works: comparing Z against a fixed
 *   threshold is exactly the definition of "did he clear the threshold".
 *
 *   Subtle point that makes the integer division safe here: because the test
 *   is STRICT (Z > half), flooring the half does not change any answer.
 *     - X*Y even (=2k):   floor = k;   Z>k  <=> Z > X*Y/2 as reals.  OK.
 *     - X*Y odd  (=2k+1): floor = k;   real half is k+0.5; Z>k means Z>=k+1,
 *                         which is the same as Z > k+0.5 for integer Z. OK.
 *   So truncation is harmless *only* because the comparison is strict. If the
 *   intended rule were "at least half" (Z >= half), this same code would be
 *   WRONG on odd totals - see EDGE CASES.
 *
 * WALKTHROUGH (this code, line by line)
 *   - cin >> T                : number of test cases.
 *   - loop i in [0, T)        : handle each case independently.
 *   - cin >> X >> Y >> Z       : read the three integers (done as 3 reads).
 *   - X*Y/2 < Z               : evaluated left-to-right as ((X*Y)/2) < Z.
 *                               '*' and '/' share precedence and associate
 *                               left, so it is (X*Y) first, THEN /2 (integer
 *                               division / truncation), THEN compared to Z.
 *   - print "YES" / "NO"       : with endl (flushes each line; fine at this
 *                               input size).
 *
 *   Dry run on T=2:
 *     Case 1: X=3, Y=3, Z=5  -> X*Y=9, 9/2=4 (floor), 4<5 true  -> "YES"
 *     Case 2: X=3, Y=3, Z=4  -> X*Y=9, 9/2=4 (floor), 4<4 false -> "NO"
 *     (real half of 9 is 4.5; Z=5 clears it, Z=4 does not - matches.)
 *
 * COMPLEXITY
 *   Time  : O(T). Constant work per test case - one multiply, one divide,
 *           one compare; the only scaling factor is the number of cases.
 *   Space : O(1). Four scalars reused across the loop; nothing is stored.
 *
 * EDGE CASES
 *   - Exactly half (Z == X*Y/2): prints NO. Correct for a STRICT "more than
 *     half" rule. If the real rule is "half or more", this is a bug at the
 *     boundary - verify against the statement before trusting it.
 *   - Odd total with a "at least half" rule: e.g. X*Y=5, half=2.5. Code uses
 *     floor 2, so Z=3 -> YES either way, but the boundary interpretation only
 *     stays correct under the strict reading (see INTUITION).
 *   - Overflow: X*Y is computed in int. This is safe only while X*Y fits in a
 *     32-bit int (~2.1e9). For a 519-rated problem the limits are almost
 *     certainly small (typically <= 100 or 1000), so int is fine here; but if
 *     X,Y could reach ~1e5+, X*Y would overflow and the compare to Z (also
 *     int) would silently give wrong answers. Using long long for X,Y,Z would
 *     remove that risk at zero cost.
 *   - Z is only ever read, never negative-guarded; the pure comparison needs
 *     no special handling for zero or small values.
 *
 * This is already optimal: O(1) per query is the best possible for a single
 * arithmetic threshold test, so no better algorithm exists. The only defensive
 * tweak worth making is widening the types to long long as noted above.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y, Z;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    cin >> Z;

	    if(X*Y/2 < Z){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

	return 0;



}
