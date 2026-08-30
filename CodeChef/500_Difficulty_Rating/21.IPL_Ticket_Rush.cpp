/*
 * CodeChef IPLTRSH - IPL Ticket Rush [273]
 *
 * @platform   CodeChef
 * @id         IPLTRSH
 * @title      IPL Ticket Rush
 * @difficulty 273
 * @topics     Basic Math, Implementation
 * @pattern    Clamped Subtraction (max(0, N-M))
 * @url        https://www.codechef.com/problems/IPLTRSH
 * @solved     2026-06-07
 *
 * Problem
 * T test cases.
 *
 * Approach
 * The answer is simply max(0, N - M). The only subtlety is the floor at 0: "fans without a
 * ticket" can never be negative, so surplus tickets must NOT turn into a negative count.
 *
 * Complexity
 * Time: O(T) - a constant amount of work (one compare, one subtract) per test case, so
 * total time is linear in the number of cases.
 * Space: O(1) - only a handful of scalar ints are held at once; no arrays.
 *
 * Notes
 * - N == M (exactly enough tickets): N > M is false -> prints 0.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, M;

	cin >> T;

	for (int i = 0; i < T; i++){

	    cin >> N;

	    cin >> M;

	    if (N > M){

	        cout << N-M << endl;

	    }

	    else{

	        cout << 0 << endl;

	    }

	}



}
