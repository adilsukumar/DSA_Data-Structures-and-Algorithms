/*
 * Platform: CodeChef
 * Submission: 1291599487
 * Problem: TRUESCORE
 * Verdict: Accepted
 * Submitted: 2026-06-19
 * Recorded in repository: 2026-09-24
 * Variant: Optimized (inferred from submission order)
 * URL: https://www.codechef.com/problems/TRUESCORE
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, A, B, C, D;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> A >> B;

	    cin >> C >> D;

	    if((A<=C && B<=D)){

	        cout << "POSSIBLE" << endl;

	    }

	    else{

	        cout << "IMPOSSIBLE" << endl;

	    }

	}

	return 0;

}

