/*
 * Platform: CodeChef
 * Submission: 1287653014
 * Problem: OFFICE
 * Verdict: Accepted
 * Submitted: 2026-06-09
 * Recorded in repository: 2026-09-24
 * Variant: Brute Force (inferred from submission order)
 * URL: https://www.codechef.com/problems/OFFICE
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
	    cout << X*4 + Y << endl;
	}
	return 0;
}
