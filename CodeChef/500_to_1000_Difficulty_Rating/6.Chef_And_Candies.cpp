/*
 * ============================================================================
 * CodeChef CHEFCAND - Chef And Candies                      Difficulty: 570
 * ============================================================================
 * @platform   CodeChef
 * @id         CHEFCAND
 * @title      Chef And Candies
 * @difficulty 570
 * @topics     Basic Math, Math
 * @pattern    Ceiling division of a shortfall
 * @url        https://www.codechef.com/problems/CHEFCAND
 * @solved     2026-06-17
 *
 * PROBLEM
 *   For each test case you are given two integers N and X: N is the number of
 *   candies Chef must end up with, and X is the number he already has. Candies
 *   can only be acquired in fixed bundles of 4 at a time. Print the minimum
 *   number of bundles Chef must obtain so that his total reaches (or exceeds) N.
 *   If he already has enough (X >= N), the answer is 0.
 *
 *   Example: N = 10, X = 3. He is short 7 candies. Bundles of 4 cover
 *   4, 8, 12, ... so 2 bundles (8 candies) are needed -> answer 2.
 *   (Note: this restatement is inferred from what the code computes -
 *   ceil((N-X)/4) - since the exact wording on CodeChef was not re-verified
 *   here. The logic below is what the code actually does, regardless.)
 *
 * INTUITION
 *   The shortfall is (N - X). Each bundle contributes exactly 4 candies, so the
 *   number of bundles is the shortfall divided by 4, ROUNDED UP - you cannot buy
 *   a fractional bundle, and any leftover need (1, 2, or 3 candies) still forces
 *   one more whole bundle. Ceiling division is the whole problem. The guard
 *   (N - X) > 0 handles the "already have enough" case, where the answer is 0
 *   rather than a negative number of bundles.
 *
 * WALKTHROUGH (this code, line by line)
 *   - Read T, the number of test cases; loop T times.
 *   - Each iteration reads N and X into the same variables.
 *   - if ((N - X) > 0): there is a real shortfall.
 *         a = N - X                  // candies still needed
 *         ceil(a / 4.0)              // a/4.0 forces DOUBLE division (not integer
 *                                    // truncation); ceil rounds up to whole bundles
 *   - else: X >= N, print 0.
 *   - cout prints the double; since ceil always yields a whole value it displays
 *     as "2", not "2.0".
 *
 *   Dry run on T=3 with (N,X) = (10,3), (5,5), (3,8):
 *     (10,3): N-X = 7 > 0  -> a = 7 -> 7/4.0 = 1.75 -> ceil = 2   -> prints 2
 *     (5,5):  N-X = 0, not > 0                                    -> prints 0
 *     (3,8):  N-X = -5, not > 0                                   -> prints 0
 *
 * COMPLEXITY
 *   Time  : O(T) total - each test case is a constant amount of arithmetic.
 *   Space : O(1) - a handful of scalar variables, no arrays or buffers.
 *
 * EDGE CASES
 *   - X == N  : shortfall is 0; the > 0 guard sends it to the else branch -> 0. Correct.
 *   - X  > N  : negative shortfall; guard catches it -> 0. Without the guard,
 *               ceil of a negative would print a wrong (negative) answer.
 *   - Shortfall an exact multiple of 4 (e.g. 8): 8/4.0 = 2.0, ceil = 2. No spurious
 *               extra bundle, because ceil of a whole number is itself.
 *   - Off-by-one trap avoided: doing integer a/4 instead of a/4.0 would truncate
 *               (7/4 = 1) and under-count. Using /4.0 + ceil is what makes it right.
 *
 * POSSIBLE IMPROVEMENT (robustness, not complexity)
 *   Complexity is already optimal - O(1) per case. The one soft spot is the use
 *   of floating point: ceil(a / 4.0) is exact for values in int range, but for
 *   very large inputs (long long territory) double loses integer precision and
 *   can round wrong. The integer-only ceiling division avoids doubles entirely:
 *
 *       long long a = N - X;
 *       cout << (a > 0 ? (a + 3) / 4 : 0) << '\n';   // (a + 3) / 4 == ceil(a/4)
 *
 *   Same answer, no floating-point risk, and '\n' over endl skips a flush per line.
 */

#include <bits/stdc++.h>

#include <cmath>

using namespace std;



int main() {

	// your code goes here

	int T, N, X, a;

	cin >> T;

	for(int i = 0; i < T; i++){

	    cin >> N >> X;

	    if((N-X) > 0){

	        a = N-X;

	        cout << ceil(a / 4.0) << endl;

	    }

	    else{

	        cout << 0 << endl;

	    }

	}

	return 0;



}
