/*
 * CodeChef CHEFCAND - Chef And Candies [570]
 *
 * @platform   CodeChef
 * @id         CHEFCAND
 * @title      Chef And Candies
 * @difficulty 570
 * @topics     Basic Math, Math
 * @pattern    Ceiling division of a shortfall
 * @url        https://www.codechef.com/problems/CHEFCAND
 * @solved     2026-06-17
 *
 * Problem
 * For each test case you are given two integers N and X: N is the number of candies Chef
 * must end up with, and X is the number he already has.
 *
 * Approach
 * The shortfall is (N - X). Each bundle contributes exactly 4 candies, so the number of
 * bundles is the shortfall divided by 4, ROUNDED UP - you cannot buy a fractional bundle,
 * and any leftover need (1, 2, or 3 candies) still forces one more whole bundle.
 *
 * Complexity
 * Time: O(T) total - each test case is a constant amount of arithmetic.
 * Space: O(1) - a handful of scalar variables, no arrays or buffers.
 *
 * Notes
 * - X == N : shortfall is 0; the > 0 guard sends it to the else branch -> 0.
 */

#include <bits/stdc++.h>

#include <cmath>

using namespace std;



int main() {

	// your code goes here

	int T, N, X, a;

	cin >> T;

	for(int i = 0; i < T; i++){

	    cin >> N >> X;

	    if((N-X) > 0){

	        a = N-X;

	        cout << ceil(a / 4.0) << endl;

	    }

	    else{

	        cout << 0 << endl;

	    }

	}

	return 0;



}
