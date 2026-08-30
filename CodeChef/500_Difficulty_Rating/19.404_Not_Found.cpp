/*
 * CodeChef ERROR404 - 404 Not Found [267]
 *
 * @platform   CodeChef
 * @id         ERROR404
 * @title      404 Not Found
 * @difficulty 267
 * @topics     Implementation, Conditionals, Basic Programming
 * @pattern    Direct Equality Check
 * @url        https://www.codechef.com/problems/ERROR404
 * @solved     2026-06-06
 *
 * Problem
 * Read a single integer X.
 *
 * Approach
 * There is nothing to compute or search. The entire task collapses to a single equality
 * test: is X the magic number 404?
 *
 * Complexity
 * Time: O(1) — one read and one comparison, independent of the input value.
 * Space: O(1) — a single int; no containers or recursion.
 *
 * Notes
 * - Negative numbers, zero, or huge values: all handled — anything that isn't 404 falls
 *   straight into the "FOUND" branch.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int X;

	cin >> X;

	if (X == 404){

	    cout << "NOT FOUND" << endl;

	}

	else{

	    cout << "FOUND" << endl;

	}



}
