/*
 * Platform: CodeChef
 * Submission: 1322362029
 * Problem: TRANSFORM
 * Verdict: Accepted
 * Submitted: 2026-07-29
 * Recorded in repository: 2026-09-24
 * Variant: Improved Approach 3 (inferred from submission order)
 * URL: https://www.codechef.com/problems/TRANSFORM
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    if(X%3 == 1){

	        cout << "HUGE" << endl;

	    }

	    else if(X%3 == 0){

	        cout << "NORMAL" << endl;

	    }

	    else{

	        cout << "SMALL" << endl;

	    }

	}

	return 0;

}

