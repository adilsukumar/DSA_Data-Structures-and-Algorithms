/*
 * Platform: CodeChef
 * Submission: 1317597279
 * Problem: FLIPCARDS
 * Verdict: Accepted
 * Submitted: 2026-07-26
 * Recorded in repository: 2026-09-24
 * Variant: Optimized (inferred from submission order)
 * URL: https://www.codechef.com/problems/FLIPCARDS
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, X;

	cin >> T;

	

	while(T--){

	    cin >> N >> X;

	    if(N == X || X == 0){

	        cout << 0 << endl;

	    }

	    else{

	        if(N >= 2*X){

	            cout << X << endl;

	        }

	        else{

	            cout << N-X << endl;

	        }

	    }

	}

	return 0;

}

