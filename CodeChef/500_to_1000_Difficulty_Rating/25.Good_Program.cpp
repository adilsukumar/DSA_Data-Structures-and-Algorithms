/*
 * ============================================================================
 * CodeChef NIBBLE - Good Program                                Difficulty 593
 * ============================================================================
 * @platform   CodeChef
 * @id         NIBBLE
 * @title      Good Program
 * @difficulty 593
 * @topics     Divisibility, Integer Division, Implementation
 * @pattern    Modulo Divisibility Check
 * @url        https://www.codechef.com/problems/NIBBLE
 * @solved     2026-07-15
 *
 * PROBLEM
 *   You are given T independent test cases. Each test case is a single integer
 *   X. A "nibble" is 4 bits, so the program is declared "Good" when X is an
 *   exact multiple of 4, and "Not Good" otherwise. Print the verdict per case.
 *
 *     Input : T=3, then X = 8, 6, 12
 *     Output: Good        (8  = 4*2)
 *             Not Good    (6  leaves remainder 2)
 *             Good        (12 = 4*3)
 *
 * INTUITION
 *   "Divisible by 4" is exactly "the remainder when dividing by 4 is zero".
 *   The modulo operator X % 4 computes that remainder directly, so a single
 *   comparison X % 4 == 0 settles each case. No loops over digits, no bit
 *   tricks needed -- one arithmetic operation carries the whole decision.
 *   (Trivia worth remembering: a number is divisible by 4 iff its last two
 *   decimal digits form a multiple of 4, but % 4 makes that shortcut moot.)
 *
 * WALKTHROUGH
 *   - `cin >> T;`            read how many test cases follow.
 *   - `for(i = 0; i < T; i++)` loop once per case; i is only a counter and is
 *                            never used inside, which is correct here.
 *   - `cin >> X;`            read the current integer.
 *   - `if (X % 4 == 0)`      the entire test: true => multiple of 4.
 *   - print "Good" / "Not Good" accordingly, each on its own line via endl.
 *
 *   Dry run on T=3, X = 8, 6, 12:
 *     i=0: X=8  -> 8 % 4 = 0        -> "Good"
 *     i=1: X=6  -> 6 % 4 = 2 (!= 0) -> "Not Good"
 *     i=2: X=12 -> 12 % 4 = 0       -> "Good"
 *   Loop ends after 3 iterations; program returns 0.
 *
 * COMPLEXITY
 *   Time : O(T) overall -- O(1) work (one modulo, one compare) per test case.
 *   Space: O(1) -- only the scalars T, X, i are stored; nothing scales with T.
 *   Note : `endl` flushes the output buffer on every line. For huge T this is
 *          measurably slower than printing "\n"; harmless at this constraint
 *          size but a habit worth breaking for heavier I/O problems.
 *
 * EDGE CASES
 *   - X = 0: 0 % 4 == 0 -> "Good". Zero is a multiple of 4, so this is right.
 *   - Negative X: in C++ the sign of % follows the dividend, e.g. (-8) % 4 == 0
 *     and (-6) % 4 == -2, so the == 0 test still classifies correctly. (This
 *     problem's inputs are non-negative, but the code is safe either way.)
 *   - Large X: fits in `int` up to ~2.1e9; if the constraints ever exceeded
 *     that, X would need to be `long long` to avoid overflow on read.
 *   - T = 0: the loop body never runs and nothing is printed -- valid.
 *
 * This is already optimal: O(1) per query with a single modulo is as tight as
 * the problem allows, so no better algorithm exists to sketch.
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

	    if(X%4 == 0){

	        cout << "Good" << endl;

	    }

	    else{

	        cout << "Not Good" << endl;

	    }

	}

	return 0;

}
