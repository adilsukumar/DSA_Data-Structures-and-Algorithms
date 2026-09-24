/*
 * Platform: CodeChef
 * Submission: 1288765454
 * Problem: CHAIRS_
 * Verdict: Accepted
 * Submitted: 2026-06-12
 * Recorded in repository: 2026-09-24
 * Variant: Improved Approach 4 (inferred from submission order)
 * URL: https://www.codechef.com/problems/CHAIRS_
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    if(X>=Y){

	        cout << X-Y << endl;

	    }

	    else{

	        cout << 0 << endl;

	    }

	}

    return 0;

}



