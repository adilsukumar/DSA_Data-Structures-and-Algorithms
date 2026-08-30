/*
 * CodeChef CNTWRD - Counting Words [296]
 *
 * @platform   CodeChef
 * @id         CNTWRD
 * @title      Counting Words
 * @difficulty 296
 * @topics     Basic Programming Concepts, Basic Math
 * @pattern    Per-test read two ints, print product
 * @url        https://www.codechef.com/problems/CNTWRD
 * @solved     2026-06-07
 *
 * Problem
 * Read T.
 *
 * Approach
 * The only "idea" present is the arithmetic identity: multiply the two numbers you were
 * handed. It works as arithmetic, but it has no bearing on counting words, so there is no
 * correctness argument to make for CNTWRD.
 *
 * Complexity
 * Time: O(T) — constant work (one multiply, one print) per test case.
 * Space: O(1) — three ints reused across all iterations; nothing scales.
 *
 * Notes
 * - Overflow: N*M is computed in `int`; large N,M silently wraps.
 * - This code multiplies two integers; it does not implement word counting.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, M;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N;

	    cin >> M;

	    cout << N*M << endl;

	}

    return 0;

}
