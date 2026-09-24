/*
 * Platform: CodeChef
 * Submission: 1310807748
 * Problem: JENGA
 * Verdict: Accepted
 * Submitted: 2026-07-19
 * Recorded in repository: 2026-09-24
 * Variant: Optimized (inferred from submission order)
 * URL: https://www.codechef.com/problems/JENGA
 *  */

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

