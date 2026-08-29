/*
 * ============================================================================
 * CodeChef HELIUM3 - Chef And NextGen                         Difficulty: 562
 * ============================================================================
 *
 * @platform   CodeChef
 * @id         HELIUM3
 * @title      Chef And NextGen
 * @difficulty 562
 * @topics     Basic Math, Implementation
 * @pattern    Compare Products of Two Pairs
 * @url        https://www.codechef.com/problems/HELIUM3
 * @solved     2026-06-16
 *
 * ---------------------------------------------------------------------------
 * PROBLEM
 * ---------------------------------------------------------------------------
 * Each test case gives four integers A, B (the current requirement) and
 * X, Y (what the next generation supplies). The task is to decide whether the
 * next-gen capacity X*Y is enough to meet the current-gen demand A*B, i.e.
 * whether  X*Y >= A*B. Print "Yes" if it is, otherwise "No".
 *
 * It is deliberately NOT (X>=A && Y>=B): only the two PRODUCTS are compared,
 * so a large Y can compensate for a small X and vice versa.
 *
 * Example: A=2, B=3, X=6, Y=1  ->  A*B = 6, X*Y = 6  ->  6 >= 6  ->  "Yes".
 *          A=2, B=3, X=2, Y=2  ->  A*B = 6, X*Y = 4  ->  4 <  6  ->  "No".
 *
 * ---------------------------------------------------------------------------
 * INTUITION
 * ---------------------------------------------------------------------------
 * There is nothing to search or optimise. The answer is a single boolean fact
 * about the input: does one product dominate the other? Reduce each pair to
 * its product (that single number is all that matters) and compare. It works
 * because the problem defines "enough" purely as area/capacity >= demand, and
 * multiplication collapses each pair into exactly that scalar.
 *
 * ---------------------------------------------------------------------------
 * WALKTHROUGH  (this code, line by line)
 * ---------------------------------------------------------------------------
 *   cin >> T;                      read the number of test cases.
 *   for i in 0..T-1:               loop once per test case. NOTE: A,B,X,Y are
 *                                  declared ONCE outside the loop and reused;
 *                                  fine here since all four are overwritten by
 *                                  the read before they are used each round.
 *     cin >> A >> B >> X >> Y;      read the two pairs for this case.
 *     if (X*Y >= A*B)  -> "Yes"     the whole problem, in one comparison.
 *     else             -> "No"
 *
 * Dry run on  T=2 / [2 3 6 1] / [2 3 2 2]:
 *   Case 1: A=2 B=3 X=6 Y=1 -> X*Y=6, A*B=6 -> 6>=6 true  -> prints "Yes"
 *   Case 2: A=2 B=3 X=2 Y=2 -> X*Y=4, A*B=6 -> 4>=6 false -> prints "No"
 *   Output:
 *     Yes
 *     No
 *
 * ---------------------------------------------------------------------------
 * COMPLEXITY
 * ---------------------------------------------------------------------------
 * Time:  O(T)  -- constant work (two multiplications, one compare) per case.
 * Space: O(1)  -- a fixed handful of int variables, nothing scales with input.
 *
 * ---------------------------------------------------------------------------
 * EDGE CASES
 * ---------------------------------------------------------------------------
 * - Equality (X*Y == A*B): the '>=' makes this "Yes", which matches "enough".
 * - Zero dimensions: if any value is 0 the product is 0; handled naturally by
 *   the arithmetic, no special-casing needed.
 * - INTEGER OVERFLOW (the real risk): A,B,X,Y are plain `int`, so each product
 *   is computed in `int`. If the constraints allow values past ~46340, the
 *   product exceeds 2^31-1 and overflows -> undefined/wrong comparison. For
 *   this easy problem the limits are almost certainly small enough that it is
 *   safe, but the code is NOT robust to larger bounds. Fix: read/compute as
 *   `long long` (see below). This is the one thing to double-check per limits.
 * - Style nit, not a bug: `endl` flushes every line; `"\n"` is faster for
 *   large T. Declaring the vars inside the loop would also read cleaner.
 *
 * ---------------------------------------------------------------------------
 * SAFER VERSION (overflow-proof; same O(T))
 * ---------------------------------------------------------------------------
 * The logic is already optimal -- there is no faster approach than one
 * comparison per case. The only improvement worth making is the integer type:
 *
 *   int T; cin >> T;
 *   while (T--) {
 *       long long A, B, X, Y;
 *       cin >> A >> B >> X >> Y;
 *       cout << (X*Y >= A*B ? "Yes" : "No") << '\n';
 *   }
 *
 * Using long long removes the overflow foot-gun regardless of the bounds.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, A, B, X, Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> A >> B >> X >> Y;

	    if(X*Y >= A*B){

	        cout << "Yes" << endl;

	    }

	    else{

	        cout << "No" << endl;

	    }

	}



}
