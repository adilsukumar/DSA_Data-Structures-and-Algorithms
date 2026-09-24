/*
 * Platform: CodeChef
 * Submission: 1307860199
 * Problem: QUALIFY
 * Verdict: Accepted
 * Submitted: 2026-07-15
 * Recorded in repository: 2026-09-24
 * Variant: Improved Approach 5 (inferred from submission order)
 * URL: https://www.codechef.com/problems/QUALIFY
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, A, B;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X >> A >> B;

	    if((A*1 + B*2) >= X){

	        cout << "Qualify" << endl;

	    }

	    else{

	        cout << "NotQualify" << endl;

	    }

	}

}