/*
 * CodeChef HELIUM3 - Chef And NextGen [562]
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
 * Problem
 * Each test case gives four integers A, B (the current requirement) and X, Y (what the
 * next generation supplies).
 *
 * Approach
 * There is nothing to search or optimise. The answer is a single boolean fact about the
 * input: does one product dominate the other?
 *
 * Complexity
 * Time: O(T) -- constant work (two multiplications, one compare) per case.
 * Space: O(1) -- a fixed handful of int variables, nothing scales with input.
 *
 * Notes
 * - Equality (X*Y == A*B): the '>=' makes this "Yes", which matches "enough".
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
