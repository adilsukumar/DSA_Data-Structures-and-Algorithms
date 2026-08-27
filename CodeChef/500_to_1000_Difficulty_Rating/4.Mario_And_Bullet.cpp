/*
 * ============================================================================
 *  CodeChef BULLET - Mario And Bullet                        Difficulty: 650
 * ============================================================================
 *  @platform   CodeChef
 *  @id         BULLET
 *  @title      Mario And Bullet
 *  @difficulty 650
 *  @topics     Math, Implementation
 *  @pattern    Time = distance / speed
 *  @url        https://www.codechef.com/problems/BULLET
 *  @solved     2026-07-27
 *
 *  PROBLEM
 *  -------
 *  Mario fires a bullet toward an enemy. The bullet travels at X units per
 *  second, and the enemy is Y units away. The enemy fires back / dies after
 *  Z seconds. We want how much time is left after Mario's bullet lands:
 *  the bullet needs Y/X seconds to cover the distance, so the answer is
 *  Z - (Y/X). If the bullet takes longer than Z seconds to arrive, it never
 *  gets its chance in time, so the answer is 0 (never negative).
 *
 *    Example: X=2, Y=6, Z=5.
 *    Bullet needs 6/2 = 3 seconds. Time remaining = 5 - 3 = 2.  -> print 2
 *
 *    Example: X=2, Y=20, Z=5.
 *    Bullet needs 20/2 = 10 seconds, which is > 5. -> print 0
 *
 *  INTUITION
 *  ---------
 *  The whole thing is one physics relation: time = distance / speed. Compute
 *  the bullet's travel time once, compare it against the deadline Z, and
 *  clamp the leftover at 0. There is no search, no data structure -- the only
 *  subtlety is remembering that a "negative remaining time" is meaningless
 *  and must be reported as 0.
 *
 *  WALKTHROUGH
 *  -----------
 *  - Read T, the number of independent test cases.
 *  - For each case, read X (speed), Y (distance), Z (deadline).
 *  - seconds_taken = Y / X. NOTE: this is INTEGER division. It floors the
 *    quotient, so e.g. Y=7, X=2 gives 3, not 3.5. This is only correct if
 *    the problem guarantees Y is a multiple of X (or explicitly wants the
 *    floor). See EDGE CASES -- this is the one place the code could be wrong
 *    on inputs where Y is not divisible by X.
 *  - If seconds_taken > Z, the bullet is too slow; print 0.
 *  - Otherwise print Z - seconds_taken, the leftover time.
 *
 *    Dry run on X=3, Y=12, Z=6:
 *      seconds_taken = 12 / 3 = 4
 *      4 > 6 ? no
 *      print 6 - 4 = 2
 *
 *    Dry run on X=5, Y=40, Z=6:
 *      seconds_taken = 40 / 5 = 8
 *      8 > 6 ? yes
 *      print 0
 *
 *  COMPLEXITY
 *  ----------
 *  Time:  O(T)   -- constant work (one division, one compare) per test case.
 *  Space: O(1)   -- only a handful of scalar ints, nothing scales with input.
 *
 *  EDGE CASES
 *  ----------
 *  - Bullet exactly on time (seconds_taken == Z): prints 0, which is correct
 *    -- there is zero time to spare, handled by the else branch (Z - Z = 0).
 *  - Bullet too slow (seconds_taken > Z): explicitly clamped to 0 rather than
 *    printing a negative number. This is the important guard.
 *  - Non-divisible distance (Y not a multiple of X): Y/X silently floors.
 *    If the real problem allows such inputs and expects a rounded-up or exact
 *    time, this undercounts seconds_taken and can over-report the remaining
 *    time. Confirm the constraints guarantee divisibility; otherwise this is
 *    a latent bug.
 *  - X == 0 would divide by zero (undefined behavior). The code assumes the
 *    problem forbids a zero-speed bullet; it does not defend against it.
 *
 *  This solution is already optimal for the task -- O(1) per query is the best
 *  achievable, so no better approach is warranted (only the integer-division
 *  caveat above is worth double-checking against the official constraints).
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y, Z;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X >> Y >> Z;

	    int seconds_taken = Y/X;

	    if(seconds_taken > Z){

	        cout << 0 << endl;

	    }

	    else{

	        cout << Z - seconds_taken << endl;

	    }

	}

	return 0;

}
