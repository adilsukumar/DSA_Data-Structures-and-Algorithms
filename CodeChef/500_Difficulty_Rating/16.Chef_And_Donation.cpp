/*
 * CodeChef DNATION - Chef And Donation [305]
 *
 * @platform   CodeChef
 * @id         DNATION
 * @title      Chef And Donation
 * @difficulty 305
 * @topics     Basic Math, Implementation
 * @pattern    Per-test subtraction (Y - X)
 * @url        https://www.codechef.com/problems/DNATION
 * @solved     2026-06-13
 *
 * Problem
 * For each test case you are given two integers X and Y, where X is the amount Chef
 * currently has and Y is the amount Chef wants to reach (the donation target).
 *
 * Approach
 * "How much is still missing to go from X up to Y" is exactly the gap between them on the
 * number line: Y - X. There is no state to carry between test cases, no ordering, no
 * search -- each query is answered by a single subtraction, so the whole task is a thin
 * loop over independent arithmetic.
 *
 * Complexity
 * Time: O(T) -- constant work (one subtraction, one print) per test case.
 * Space: O(1) -- three scalars reused; no arrays or buffers grow with input.
 *
 * Notes
 * - `cin >> T;` : read the number of test cases.
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

	    cout << Y-X << endl;

	}

	return 0;

}
