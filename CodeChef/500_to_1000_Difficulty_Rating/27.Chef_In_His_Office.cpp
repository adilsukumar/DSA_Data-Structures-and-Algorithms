/*
 * CodeChef OFFICE - Chef In His Office [532]
 *
 * @platform   CodeChef
 * @id         OFFICE
 * @title      Chef In His Office
 * @difficulty 532
 * @topics     Basic Programming, Math, Implementation
 * @pattern    Direct arithmetic formula, O(1)
 * @url        https://www.codechef.com/problems/OFFICE
 * @solved     2026-06-09
 *
 * Problem
 * For each of T independent test cases you are given two integers X and Y, and must print
 * a single derived value.
 *
 * Approach
 * There is nothing to search or sort. The answer is a closed-form linear expression in the
 * two inputs, so the entire task is: read the pair, plug into 4*X + Y, print.
 *
 * Complexity
 * Time: O(T) overall, O(1) per test case -- one multiply and one add.
 * Space: O(1) -- three scalar ints reused across iterations, no buffers.
 *
 * Notes
 * - Multiple test cases: handled by the T-loop; each case is self-contained so nothing
 *   leaks between iterations (X and Y are overwritten each time).
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    cout << X*4 + Y << endl;

	}

	return 0;

}
