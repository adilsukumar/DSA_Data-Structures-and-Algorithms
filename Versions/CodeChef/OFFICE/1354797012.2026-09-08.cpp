/*
 * Platform: CodeChef
 * Submission: 1354797012
 * Problem: OFFICE
 * Verdict: Accepted
 * Submitted: 2026-09-08
 * Recorded in repository: 2026-09-24
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
