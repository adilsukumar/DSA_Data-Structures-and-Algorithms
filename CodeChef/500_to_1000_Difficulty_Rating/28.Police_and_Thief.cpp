/*
 * ============================================================================
 * CodeChef POLTHIEF - Police and Thief                        Difficulty: 639
 * ============================================================================
 * @platform   CodeChef
 * @id         POLTHIEF
 * @title      Police and Thief
 * @difficulty 639
 * @topics     Basic Math, Implementation
 * @pattern    Absolute Difference |X - Y|
 * @url        https://www.codechef.com/problems/POLTHIEF
 * @solved     2026-07-19
 *
 * ---------------------------------------------------------------------------
 * PROBLEM
 * ---------------------------------------------------------------------------
 * A police officer stands at position X and a thief at position Y on a line.
 * For each of T test cases, report the distance between them, i.e. how many
 * steps apart they are. Since a distance can never be negative, the answer is
 * the absolute value of their positional difference: |X - Y|.
 *
 *   Example: X = 3, Y = 8  ->  |3 - 8| = 5
 *            X = 9, Y = 4  ->  |9 - 4| = 5
 *            X = 6, Y = 6  ->  0   (same spot)
 *
 * ---------------------------------------------------------------------------
 * INTUITION
 * ---------------------------------------------------------------------------
 * Distance on a number line is direction-agnostic: whether the police is left
 * or right of the thief, the gap between them is the same magnitude. That gap
 * is |X - Y|. The only subtlety is that plain subtraction X - Y can be
 * negative (when Y > X), and printing a negative "distance" would be wrong.
 * So we branch on which value is larger and always subtract smaller from
 * larger. That guarantees a non-negative result -- it is just abs() written
 * out by hand, and it works because exactly one of the two branches produces
 * the non-negative difference.
 *
 * ---------------------------------------------------------------------------
 * WALKTHROUGH (this code)
 * ---------------------------------------------------------------------------
 *   cin >> T;                 read the number of test cases
 *   for i in [0, T):          process each case independently
 *       cin >> X >> Y;        read the two positions for this case
 *       if (X >= Y)           police at/right of thief -> X - Y is >= 0
 *           print X - Y
 *       else                  thief is further right    -> Y - X is > 0
 *           print Y - X
 *
 * The >= (not >) in the first branch matters only for the tie X == Y: it
 * routes into the first branch and prints X - Y == 0, which is correct. The
 * else branch is reachable strictly when Y > X, so Y - X there is always
 * positive. Every path prints a value >= 0.
 *
 * Dry run on input:
 *   T = 3
 *   (X,Y) = (3,8): 3 >= 8? no  -> else -> print 8 - 3 = 5
 *   (X,Y) = (9,4): 9 >= 4? yes -> if   -> print 9 - 4 = 5
 *   (X,Y) = (6,6): 6 >= 6? yes -> if   -> print 6 - 6 = 0
 *   Output: 5 / 5 / 0
 *
 * ---------------------------------------------------------------------------
 * COMPLEXITY
 * ---------------------------------------------------------------------------
 * Time  : O(T)   -- constant work (one compare, one subtract, one print) per
 *                   test case; nothing is stored or revisited.
 * Space : O(1)   -- three int scalars reused across all iterations; no arrays.
 *
 * ---------------------------------------------------------------------------
 * EDGE CASES
 * ---------------------------------------------------------------------------
 * - X == Y (same position): handled by the >= branch, prints 0. Correct.
 * - Y > X (thief to the right): the else branch flips the operands so the
 *   result stays non-negative. This is the case a naive `cout << X - Y` would
 *   get wrong, and the branch exists precisely to cover it.
 * - Overflow: int holds values up to ~2.1e9. If the constraints allowed
 *   X or Y near that bound this would still be safe since the difference only
 *   shrinks, but if positions could exceed int range, switch to long long.
 *   For this problem's small constraints, int is fine.
 * - endl flushes the output buffer on every line. Harmless at this scale, but
 *   for very large T prefer '\n' to avoid per-line flush overhead.
 *
 * ---------------------------------------------------------------------------
 * NOTE ON OPTIMALITY
 * ---------------------------------------------------------------------------
 * This solution is already optimal in both time and space -- you cannot beat
 * O(1) per query. The only stylistic simplification is replacing the if/else
 * with the library abs(), which is the same idea in one line:
 *
 *     cout << abs(X - Y) << '\n';
 *
 * (Use long long / llabs if positions can exceed int range.) The explicit
 * branch the author wrote is not wrong -- it is abs() spelled out -- so this
 * is purely a readability preference, not a correctness or performance fix.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X >> Y;

	    if(X >= Y){

	        cout << X-Y << endl;

	    }

	    else{

	        cout << Y-X << endl;

	    }

	}

	return 0;

}
