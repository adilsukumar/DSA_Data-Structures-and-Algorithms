/*
 * CodeChef KITCHENTIME - Kitchen Timings [273]
 *
 * @platform   CodeChef
 * @id         KITCHENTIME
 * @title      Kitchen Timings
 * @difficulty 273
 * @topics     Basic Math, Implementation
 * @pattern    Per-query subtraction (Y - X)
 * @url        https://www.codechef.com/problems/KITCHENTIME
 * @solved     2026-06-06
 *
 * Problem
 * There are T independent test cases.
 *
 * Approach
 * The duration between two points on a single timeline is just the end minus the start.
 * There is no wraparound, no clock arithmetic, no accumulation across cases — each case is
 * fully answered by one subtraction.
 *
 * Complexity
 * Time: O(T) — a constant amount of work (two reads, one subtraction, one print) per test
 * case, so total work scales linearly with T.
 * Space: O(1) — only the scalars T, X, Y are stored; nothing grows with input.
 *
 * Notes
 * - X == Y: prints 0, the correct zero-length duration.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	for (int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    cout << Y-X << endl;

	}

	return 0;



}
