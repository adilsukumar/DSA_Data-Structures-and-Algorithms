/*
 * CodeChef ACTEMP - Air Conditioner Temperature [584]
 *
 * @platform   CodeChef
 * @id         ACTEMP
 * @title      Air Conditioner Temperature
 * @difficulty 584
 * @topics     Basic Programming, Basic Math, Comparisons
 * @pattern    Threshold check on max of two values
 * @url        https://www.codechef.com/problems/ACTEMP
 * @solved     2026-06-23
 *
 * Problem
 * For each test case you are given three integers A, B, C.
 *
 * Approach
 * Two independent conditions "A <= B" and "C <= B" can be folded into one: the *larger* of
 * A and C is the only one that can break the ceiling. If the bigger of the two already
 * fits under B, the smaller one trivially does too.
 *
 * Complexity
 * Time: O(T) overall -- O(1) work per test case (one max + one compare).
 * Space: O(1) -- only a handful of int scalars, reused each iteration.
 *
 * Notes
 * - A == B or C == B: the "<=" is inclusive, so equal-to-ceiling counts as fitting ->
 *   "Yes".
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, A, B, C;

	cin >> T;

	

	while(T--){

	    cin >> A >> B >> C;

    	if(max(A,C) <= B){

    	    cout << "Yes" << endl;

    	}

    	else{

    	    cout << "No" << endl;

    	}

	}

    return 0;

}
