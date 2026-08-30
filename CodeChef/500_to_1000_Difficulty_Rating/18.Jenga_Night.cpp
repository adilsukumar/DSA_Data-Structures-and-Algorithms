/*
 * CodeChef JENGA - Jenga Night [613]
 *
 * @platform   CodeChef
 * @id         JENGA
 * @title      Jenga Night
 * @difficulty 613
 * @topics     Math
 * @pattern    Divisibility Check (X % N == 0)
 * @url        https://www.codechef.com/problems/JENGA
 * @solved     2026-07-19
 *
 * Problem
 * A Jenga tower is built in complete levels, each level using exactly N blocks.
 *
 * Approach
 * "Fill k complete levels of N blocks each" means the total X must equal k*N for some
 * integer k >= 1. That is exactly the statement "X is a positive multiple of N": X leaves
 * no remainder when divided by N (X % N == 0), AND X is large enough to form at least one
 * level (X >= N).
 *
 * Complexity
 * Time: O(T) -- constant work (one comparison, one modulo) per test case.
 * Space: O(1) -- only the scalars T, N, X are stored; no arrays.
 *
 * Notes
 * - X == 0 (no blocks): X % N == 0 would say "yes", but the `X >= N` guard correctly
 *   forces "NO" (you cannot build a tower from nothing).
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N >> X;

	    if(X >= N && X%N == 0){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

    return 0;

}
