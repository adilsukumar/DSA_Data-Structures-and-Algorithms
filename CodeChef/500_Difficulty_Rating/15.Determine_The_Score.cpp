/*
 * CodeChef DETSCORE - Determine The Score [267]
 *
 * @platform   CodeChef
 * @id         DETSCORE
 * @title      Determine The Score
 * @difficulty 267
 * @topics     Basic Programming Concepts, Basic Math
 * @pattern    Integer Division then Multiply
 * @url        https://www.codechef.com/problems/DETSCORE
 * @solved     2026-06-05
 *
 * Problem
 * A group of X students each solved N problems.
 *
 * Approach
 * The whole task is a single arithmetic expression, so the only real decision is the ORDER
 * of operations. The code divides FIRST ((X/TG)*N), which is exactly right: it counts how
 * many complete groups of 10 exist, then scales by N.
 *
 * Complexity
 * Time: O(T) -- constant work (one divide, one multiply) per test case.
 * Space: O(1) -- four ints reused across every iteration; nothing stored.
 *
 * Notes
 * - X < 10 -> X/10 = 0, so the score is 0.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int TG, T, X, N;

	TG = 10;

	cin >> T;

	for(int i = 0; i < T; i++){

	    cin >> X;

	    cin >> N;

	    cout << (X/TG) * N << endl;

	}

	return 0;

}
