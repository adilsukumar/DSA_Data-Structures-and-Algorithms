/*
 * Platform: CodeChef
 * Submission: 1286886692
 * Problem: SUBSCRIBE_
 * Verdict: Accepted
 * Submitted: 2026-06-08
 * Recorded in repository: 2026-09-24
 * Variant: Brute Force (inferred from submission order)
 * URL: https://www.codechef.com/problems/SUBSCRIBE_
 *  */

#include <bits/stdc++.h>

#include <cmath>

using namespace std;



int main() {

	// your code goes here

	int T, N, X;

	cin >> T;

	for (int i = 0; i < T; i++){

	    cin >> N;

	    cin >> X;

	    if (N<6){

	        cout << X << endl;

	    }

	    else if (N%6 == 0){

	        cout << X * (N/6) << endl;

	    }

	    else{

	        cout << X * ceil(double(N)/6) << endl;

	    }

	}

}

