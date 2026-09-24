/*
 * Platform: CodeChef
 * Submission: 1317604570
 * Problem: BATH
 * Verdict: Accepted
 * Submitted: 2026-07-26
 * Recorded in repository: 2026-09-24
 * Variant: Brute Force (inferred from submission order)
 * URL: https://www.codechef.com/problems/BATH
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	while(T--){

	    cin >> X >> Y;

	    if(Y*2 > X){

	        cout << 0 << endl;

	    }

	    else{

	        cout << floor(X/(2*Y)) << endl;

	    }

	}

	return 0;

}

