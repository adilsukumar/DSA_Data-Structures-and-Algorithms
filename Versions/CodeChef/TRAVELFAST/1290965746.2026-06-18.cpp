/*
 * Platform: CodeChef
 * Submission: 1290965746
 * Problem: TRAVELFAST
 * Verdict: Accepted
 * Submitted: 2026-06-18
 * Recorded in repository: 2026-09-24
 * Variant: Improved Approach 3 (inferred from submission order)
 * URL: https://www.codechef.com/problems/TRAVELFAST
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T,X,Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X >> Y;

	    if(X>Y){

	        cout << "CAR" << endl;

	    }

	    else if(Y>X){

	        cout << "BIKE" << endl;

	    }

	    else{

	        cout << "SAME" << endl;

	    }

	}

	return 0;

}

