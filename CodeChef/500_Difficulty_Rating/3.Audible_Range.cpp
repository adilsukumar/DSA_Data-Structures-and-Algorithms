/*
 * CodeChef AUDIBLE - Audible Range [279]
 *
 * @platform   CodeChef
 * @id         AUDIBLE
 * @title      Audible Range
 * @difficulty 279
 * @topics     Basic Math, Implementation
 * @pattern    Range Membership Check
 * @url        https://www.codechef.com/problems/AUDIBLE
 * @solved     2026-06-07
 *
 * Problem
 * The audible range (here, the frequencies a dog can hear) spans 67 Hz to 45000 Hz
 * inclusive.
 *
 * Approach
 * There is no algorithm to design here -- the whole task is a definition lookup. "Inside a
 * closed interval [lo, hi]" is exactly the compound condition (X >= lo && X <= hi).
 *
 * Complexity
 * Time: O(T) -- one read and two constant-time comparisons per test case.
 * Space: O(1) -- only the scalars T, X, i; nothing scales with input size.
 *
 * Notes
 * - Exact endpoints 67 and 45000: accepted, because the operators are inclusive (>=, <=).
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	for (int i = 0; i < T; i++){

	    cin >> X;

	    if (X >= 67 && X <= 45000){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

	return 0;

}
