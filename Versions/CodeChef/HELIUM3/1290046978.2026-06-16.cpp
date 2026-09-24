/*
 * Platform: CodeChef
 * Submission: 1290046978
 * Problem: HELIUM3
 * Verdict: Accepted
 * Submitted: 2026-06-16
 * Recorded in repository: 2026-09-24
 * Variant: Improved Approach 2 (inferred from submission order)
 * URL: https://www.codechef.com/problems/HELIUM3
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, A, B, X, Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> A >> B >> X >> Y;

	    if(X*Y >= A*B){

	        cout << "Yes" << endl;

	    }

	    else{

	        cout << "No" << endl;

	    }

	}



}

