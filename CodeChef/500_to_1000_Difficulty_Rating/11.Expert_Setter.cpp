/*
 * ============================================================================
 *  CodeChef - Expert Setter                                    Difficulty 561
 * ============================================================================
 *  @platform   CodeChef
 *  @id         EXPERT
 *  @title      Expert Setter
 *  @difficulty 561
 *  @topics     Basic Math, Implementation
 *  @pattern    Constant-time inequality check
 *  @url        https://www.codechef.com/problems/EXPERT
 *  @solved     2026-06-15
 *
 *  PROBLEM
 *  -------
 *  For each of T independent test cases you are given two integers X and Y.
 *  The task reduces to a single yes/no decision: is Y at least half of X?
 *  Equivalently (avoiding fractions): is  2*Y >= X ?  Print "YES" if so,
 *  otherwise "NO".
 *
 *      Example:  X = 10, Y = 5  ->  2*5 = 10 >= 10  ->  YES
 *                X = 10, Y = 4  ->  2*4 =  8 < 10   ->  NO
 *
 *  Intuitively X is a required total (e.g. problems to prepare / a threshold)
 *  and Y is what is already available; you "qualify" once you have covered at
 *  least half.
 *
 *  INTUITION
 *  ---------
 *  The whole problem is one comparison. The only genuinely useful trick is to
 *  test  2*Y >= X  instead of  Y >= X/2. Integer division  X/2  would round
 *  down (e.g. X = 7 -> X/2 = 3), silently accepting Y = 3 when a true "half"
 *  is 3.5. Multiplying both sides by 2 keeps the arithmetic exact and dodges
 *  that rounding bug entirely. That is why the code is correct as written.
 *
 *  WALKTHROUGH
 *  -----------
 *    cin >> T;                     read how many test cases follow
 *    for i in 0..T-1:
 *        cin >> X; cin >> Y;       read the pair for this case
 *        if (Y*2 >= X) print YES   the qualifying condition
 *        else          print NO
 *
 *  Note the read order: X is read first, then Y, matching the "X then Y"
 *  input format. Each answer is emitted immediately, so no results are stored.
 *
 *  Dry run on:
 *      T = 3
 *      6 3     -> 2*3 = 6  >= 6  -> YES
 *      9 4     -> 2*4 = 8  <  9  -> NO
 *      1 5     -> 2*5 = 10 >= 1  -> YES   (Y may exceed X; still fine)
 *  Output:
 *      YES
 *      NO
 *      YES
 *
 *  COMPLEXITY
 *  ----------
 *  Time  : O(T) overall, O(1) per test -- one multiply and one compare each.
 *  Space : O(1) -- three scalar ints reused across every iteration; nothing
 *          is accumulated.
 *
 *  EDGE CASES
 *  ----------
 *  - Exact half (2*Y == X): the `>=` includes equality, so a precise half
 *    counts as YES. Correct for a "at least half" reading.
 *  - Odd X (e.g. X = 7): handled exactly because the code never divides;
 *    2*Y >= 7 needs Y >= 4, which is the right ceiling of 3.5.
 *  - Y >= X: trivially YES, as shown above; no special-casing needed.
 *  - Overflow: `Y*2` is computed in `int`. Safe for the small constraints
 *    typical of a 561-rated problem (values well under ~10^9). If Y could
 *    approach INT_MAX/2 this would overflow -- prefer `long long` or rewrite
 *    as `Y >= X - Y` to be safe. Not a bug at the intended limits, worth
 *    knowing for the interview.
 *
 *  NOTES
 *  -----
 *  Already optimal: O(1) per query is the theoretical floor for a comparison,
 *  so there is no better algorithm. The only stylistic tweak for large T is
 *  dropping `endl` (which force-flushes) in favor of '\n' plus
 *  ios_base::sync_with_stdio(false); to speed up I/O -- irrelevant to
 *  correctness here.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	for (int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    

	    if(Y*2 >= X){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}



}
