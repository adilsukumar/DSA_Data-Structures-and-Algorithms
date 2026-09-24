/*
 * Platform: CodeChef
 * Submission: 1286076880
 * Problem: TAXSAVING
 * Verdict: Accepted
 * Submitted: 2026-06-05
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/TAXSAVING
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X, Y;
	cin >> T;
	cout << endl;
	
	for (int i = 1; i <= T; i++){
	    cin >> X;
	    cin >> Y;
	    cout << X-Y << endl;
	}
}
