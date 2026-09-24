/*
 * Platform: CodeChef
 * Submission: 1288095328
 * Problem: FOURTICKETS
 * Verdict: Accepted
 * Submitted: 2026-06-11
 * Recorded in repository: 2026-09-24
 * Variant: Optimized (inferred from submission order)
 * URL: https://www.codechef.com/problems/FOURTICKETS
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    if(X*4 <= 1000){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

	return 0;

}

