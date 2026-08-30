/*
 * CodeChef PRIZEPOOL - Total Prize Money [296]
 *
 * @platform   CodeChef
 * @id         PRIZEPOOL
 * @title      Total Prize Money
 * @difficulty 296
 * @topics     Basic Math, Implementation
 * @pattern    O(1) closed-form arithmetic per test
 * @url        https://www.codechef.com/problems/PRIZEPOOL
 * @solved     2026-06-07
 *
 * Problem
 * For each test case you are given two counts, X and Y, describing how many winners fall
 * into each of two prize tiers.
 *
 * Approach
 * There is nothing to search or optimize: each winner's payout depends only on which tier
 * they are in, not on the other winners. So the total is just a weighted sum of two
 * independent counts.
 *
 * Complexity
 * Time: O(T).
 * Space: O(1).
 *
 * Notes
 * - X = 0 or Y = 0: that tier contributes 0 naturally (10*0 or 90*0), so an all-tier-1 or
 *   all-tier-2 case is handled with no special code.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y, R;

	cin >> T;

	

	for (int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    R = (X*10);

	    cout << R + 90*Y << endl;

	}

    return 0;

}
