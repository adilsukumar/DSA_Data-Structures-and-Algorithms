/*
 * CodeChef NOTEBOOK - Count The Notebooks [563]
 *
 * @platform   CodeChef
 * @id         NOTEBOOK
 * @title      Count The Notebooks
 * @difficulty 563
 * @topics     Basic Math, Implementation
 * @pattern    Direct closed-form formula (10*N)
 * @url        https://www.codechef.com/problems/NOTEBOOK
 * @solved     2026-06-17
 *
 * Problem
 * For each of T independent test cases you are given one integer N.
 *
 * Approach
 * There is nothing to search or iterate: the output is a fixed linear function of the
 * input. The only "idea" is recognizing the arithmetic collapses to a single
 * multiplication.
 *
 * Complexity
 * Time: O(T) -- one read and one O(1) arithmetic step per test case.
 * Space: O(1) -- only the scalars T, N, a, i; nothing scales with input.
 *
 * Notes
 * - Exact division: (N*1000) is always a multiple of 100, so a/100 never truncates away a
 *   real value.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, a;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N;

	    a = N * 1000;

	    cout << a/100 << endl;

	}

	return 0;

}
