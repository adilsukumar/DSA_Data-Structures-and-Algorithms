/*
 * CodeChef DONDRIVE - Donation Drive [272]
 *
 * @platform   CodeChef
 * @id         DONDRIVE
 * @title      Donation Drive
 * @difficulty 272
 * @topics     Basic Math, Implementation
 * @pattern    Direct Subtraction
 * @url        https://www.codechef.com/problems/DONDRIVE
 * @solved     2026-06-06
 *
 * Problem
 * A donation drive needs to raise a total of N (rupees/units).
 *
 * Approach
 * "Amount remaining" is just goal minus what you have: N - X. There is no state carried
 * between test cases and no interaction between N and X beyond a single subtraction, so
 * the whole problem collapses to one arithmetic op per query.
 *
 * Complexity
 * Time: O(T) -- constant work (one subtraction, one print) per test case.
 * Space: O(1) -- three int scalars reused across iterations; nothing stored.
 *
 * Notes
 * - X == N -> prints 0.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, X;

	cin >> T;

	

	for (int i = 0; i < T; i++){

	    cin >> N;

	    cin >> X;

	    cout << N-X << endl;

	}

	return 0;



}
