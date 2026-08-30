/*
 * CodeChef MINPIZZA - Minimum Pizzas [546]
 *
 * @platform   CodeChef
 * @id         MINPIZZA
 * @title      Minimum Pizzas
 * @difficulty 546
 * @topics     Basic Math, Implementation
 * @pattern    Integer Ceiling Division
 * @url        https://www.codechef.com/problems/MINPIZZA
 * @solved     2026-06-10
 *
 * Problem
 * There are N people and each person wants exactly X slices of pizza.
 *
 * Approach
 * Total slices required = N * X. Since a pizza is indivisible and yields 4 slices, the
 * answer is ceil(N*X / 4) -- you can never buy a fraction of a pizza, so any remaining
 * slice-demand forces one more whole pizza.
 *
 * Complexity
 * Time: O(T) -- constant work (one multiply, add, divide) per test case.
 * Space: O(1) -- only a handful of scalar ints regardless of input size.
 *
 * Notes
 * - Exact multiples of 4 (N*X % 4 == 0): the +3 stays below the next multiple, so no
 *   spurious extra pizza.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N;

	    cin >> X;

	    cout << (N*X+3) / 4 << endl; 

	}

	return 0;

}
