/*
 * CodeChef ELECTN - Elections In Chefland [604]
 *
 * @platform   CodeChef
 * @id         ELECTN
 * @title      Elections In Chefland
 * @difficulty 604
 * @topics     Implementation, Loops, Conditional Statements
 * @pattern    Single-pass threshold counting
 * @url        https://www.codechef.com/problems/ELECTN
 * @solved     2026-06-28
 *
 * Problem
 * For each test case you are given a count N and a threshold X, followed by N integers.
 *
 * Approach
 * The answer is just a population count over a fixed predicate ("value >= X"). There is no
 * ordering, no relationship between the values, and each element is judged independently.
 *
 * Complexity
 * Time: O(N) per test case, O(sum of N) overall -- each value is touched exactly once,
 * with O(1) work (one comparison) per value.
 * Space: O(1) -- only a handful of scalars; the input is never stored.
 *
 * Notes
 * - N = 0: the inner loop never executes, count stays 0, prints 0.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, X, Z;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    int count = 0;

	    cin >> N >> X;

	    for(int j = 0; j < N; j++){

	        cin >> Z;

            if (Z >= X){

                count ++;

            }

	    }

    cout << count << endl;

	}

}
