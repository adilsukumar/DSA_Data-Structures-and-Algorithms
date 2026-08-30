/*
 * CodeChef BIRYANI - Biryani Classes [257]
 *
 * @platform   CodeChef
 * @id         BIRYANI
 * @title      Biryani Classes
 * @difficulty 257
 * @topics     Basic Programming, Implementation, Math
 * @pattern    Per-test multiply two integers
 * @url        https://www.codechef.com/problems/BIRYANI
 * @solved     2026-06-05
 *
 * Problem
 * There are T independent test cases.
 *
 * Approach
 * There is no algorithm here at all -- the "answer" is defined as the product. The only
 * real skill being tested is the standard competitive-programming I/O shape: read a count
 * T, then loop T times reading a fixed set of inputs and emitting one line of output per
 * test.
 *
 * Complexity
 * Time: O(T) overall -- constant work (one multiply, one print) per test.
 * Space: O(1) -- three int variables reused across all iterations; no arrays.
 *
 * Notes
 * - int overflow: this is the ONLY real risk.
 * - Use long long if X * Y can exceed int.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	for(int i = 1; i <= T; i++){

	    cin >> X;

	    cin >> Y;

	    cout << X*Y << endl;

	}

}
