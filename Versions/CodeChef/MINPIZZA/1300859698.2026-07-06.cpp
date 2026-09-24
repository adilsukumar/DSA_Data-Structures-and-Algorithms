/*
 * Platform: CodeChef
 * Submission: 1300859698
 * Problem: MINPIZZA
 * Verdict: Accepted
 * Submitted: 2026-07-06
 * Recorded in repository: 2026-09-24
 * Variant: Improved Approach 13 (inferred from submission order)
 * URL: https://www.codechef.com/problems/MINPIZZA
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N;

	    cin >> X;

	    cout << (N*X+3) / 4 << endl; 

	}

	return 0;

}

