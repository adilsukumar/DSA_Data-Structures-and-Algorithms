/*
 * CodeChef AGEING - Ageing [299]
 *
 * @platform   CodeChef
 * @id         AGEING
 * @title      Ageing
 * @difficulty 299
 * @topics     Basic Math, Implementation
 * @pattern    Constant Offset Per Query
 * @url        https://www.codechef.com/problems/AGEING
 * @solved     2026-06-10
 *
 * Problem
 * You are given T independent test cases.
 *
 * Approach
 * There is no algorithm to design here. The map from input to output is the affine
 * function f(X) = X - 10, the same for every test case.
 *
 * Complexity
 * Time: O(T) -- one read, one subtraction, one print per test case; the per-case work is
 * constant.
 * Space: O(1) -- only the two scalars T and X are held; nothing scales with the number of
 * test cases.
 *
 * Notes
 * - X = 10 -> 0.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    cout << X-10 << endl;

	}

	return 0;



}
