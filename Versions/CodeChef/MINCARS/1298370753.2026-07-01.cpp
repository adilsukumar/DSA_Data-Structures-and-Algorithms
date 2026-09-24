/*
 * Platform: CodeChef
 * Submission: 1298370753
 * Problem: MINCARS
 * Verdict: Accepted
 * Submitted: 2026-07-01
 * Recorded in repository: 2026-09-24
 * Variant: Improved Approach 12 (inferred from submission order)
 * URL: https://www.codechef.com/problems/MINCARS
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N;

	    if(N <= 4){

	        cout << 1 << endl;

	    }

	    else{

	        cout << ceil(N/4.0) << endl;

	    }

	}



}

