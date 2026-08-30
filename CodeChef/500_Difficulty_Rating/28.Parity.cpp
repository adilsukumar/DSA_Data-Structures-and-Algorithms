/*
 * CodeChef PAR2 - Parity [295]
 *
 * @platform   CodeChef
 * @id         PAR2
 * @title      Parity
 * @difficulty 295
 * @topics     Basic Math, Implementation
 * @pattern    Even/Odd Modulo Check
 * @url        https://www.codechef.com/problems/PAR2
 * @solved     2026-06-07
 *
 * Problem
 * You are given T independent test cases.
 *
 * Approach
 * Parity is just "is there a remainder when you halve the number." An integer is even
 * exactly when it is divisible by 2, i.e. N % 2 == 0.
 *
 * Complexity
 * Time: O(T) -- one constant-work modulo test per test case, no inner work.
 * Space: O(1) -- only T, N, and the loop counter are stored; output is streamed, nothing
 * is buffered per case.
 *
 * Notes
 * - N = 0: 0 % 2 == 0 -> "YES".
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N;

	cin >> T;

	

	for (int i = 0; i < T; i++){

	    cin >> N;

	    if(N%2 == 0){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

    return 0;

}
