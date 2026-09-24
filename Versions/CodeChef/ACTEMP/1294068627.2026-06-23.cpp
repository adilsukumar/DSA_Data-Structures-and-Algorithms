/*
 * Platform: CodeChef
 * Submission: 1294068627
 * Problem: ACTEMP
 * Verdict: Accepted
 * Submitted: 2026-06-23
 * Recorded in repository: 2026-09-24
 * Variant: Brute Force (inferred from submission order)
 * URL: https://www.codechef.com/problems/ACTEMP
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, A, B, C;

	cin >> T;

	

	while(T--){

	    cin >> A >> B >> C;

    	if(max(A,C) <= B){

    	    cout << "Yes" << endl;

    	}

    	else{

    	    cout << "No" << endl;

    	}

	}

    return 0;

}

