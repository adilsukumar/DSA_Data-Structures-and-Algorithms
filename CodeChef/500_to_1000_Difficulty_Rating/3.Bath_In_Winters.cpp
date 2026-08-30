/*
 * CodeChef BATH - Bath In Winters [643]
 *
 * @platform   CodeChef
 * @id         BATH
 * @title      Bath In Winters
 * @difficulty 643
 * @topics     Math, Implementation, Integer Division
 * @pattern    Count how many times 2Y fits in X
 * @url        https://www.codechef.com/problems/BATH
 * @solved     2026-07-26
 *
 * Problem
 * For each test case you are given two integers X and Y.
 *
 * Approach
 * Each unit costs a fixed 2*Y. With a fixed budget X and a fixed per-unit cost, the
 * maximum number of whole units is just the floor division X / (2*Y).
 *
 * Complexity
 * Time: O(T).
 * Space: O(1).
 *
 * Notes
 * - 2*Y > X (can't afford even one unit): handled -> outputs 0, both by the explicit guard
 *   and, redundantly, by the division itself.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	while(T--){

	    cin >> X >> Y;

	    if(Y*2 > X){

	        cout << 0 << endl;

	    }

	    else{

	        cout << floor(X/(2*Y)) << endl;

	    }

	}

	return 0;

}
