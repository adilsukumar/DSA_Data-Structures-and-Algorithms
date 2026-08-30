/*
 * CodeChef MONOPOLY2 - Monopoly [578]
 *
 * @platform   CodeChef
 * @id         MONOPOLY2
 * @title      Monopoly
 * @difficulty 578
 * @topics     Conditional Statements, Basic Math, Implementation
 * @pattern    Generalized Triangle Inequality (max vs rest)
 * @url        https://www.codechef.com/problems/MONOPOLY2
 * @solved     2026-06-21
 *
 * Problem
 * For each test case you are given four non-negative integers P, Q, R, S.
 *
 * Approach
 * This is the generalized triangle inequality. Given four amounts, exactly one of two
 * situations holds: the largest value is <= the sum of the other three (balanced), or the
 * largest value is > the sum of the other three (one dominates).
 *
 * Complexity
 * Time: O(T) overall - each test case does a fixed set of 4 comparisons, i.e.
 * Space: O(1) - five scalar ints are reused across every iteration; nothing scales with T
 * or with the input values.
 *
 * Notes
 * - Equality boundary: the test uses strict '>', so a value EQUAL to the sum of the other
 *   three (e.g.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, P, Q, R, S;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> P >> Q >> R >> S;

	    if(P > (Q+R+S) || Q > (P+R+S) || R > (P+Q+S) || S > (P+Q+R)){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

    return 0;

}
