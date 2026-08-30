/*
 * CodeChef FINDSHOES - Finding Shoes [646]
 *
 * @platform   CodeChef
 * @id         FINDSHOES
 * @title      Finding Shoes
 * @difficulty 646
 * @topics     Arithmetic, Inbuilt Functions
 * @pattern    Closed-form arithmetic per query
 * @url        https://www.codechef.com/problems/FINDSHOES
 * @solved     2026-07-25
 *
 * Problem
 * T independent test cases.
 *
 * Approach
 * There is nothing to search or iterate over: each query is a single number decided by one
 * comparison. The key observation is that the two printed formulas are one function in
 * disguise.
 *
 * Complexity
 * Time: O(T) overall, O(1) per test case - a comparison and a subtraction, no loop over
 * the values themselves.
 * Space: O(1) - three int variables reused across all test cases.
 *
 * Notes
 * - N == M : handled correctly.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, M;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N >> M;

	    if(N >= M){

	        cout << N-M + N << endl;

	    }

	    else{

	        cout << N << endl;

	    }

	}

	return 0;

}
