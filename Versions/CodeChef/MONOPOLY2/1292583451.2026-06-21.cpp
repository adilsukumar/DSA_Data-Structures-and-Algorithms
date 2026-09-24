/*
 * Platform: CodeChef
 * Submission: 1292583451
 * Problem: MONOPOLY2
 * Verdict: Accepted
 * Submitted: 2026-06-21
 * Recorded in repository: 2026-09-24
 * Variant: Improved Approach 3 (inferred from submission order)
 * URL: https://www.codechef.com/problems/MONOPOLY2
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, P, Q, R, S;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> P >> Q >> R >> S;

	    if(P > (Q+R+S) || Q > (P+R+S) || R > (P+Q+S) || S > (P+Q+R)){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

    return 0;

}

