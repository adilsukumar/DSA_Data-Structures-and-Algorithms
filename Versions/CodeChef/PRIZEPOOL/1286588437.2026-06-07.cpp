/*
 * Platform: CodeChef
 * Submission: 1286588437
 * Problem: PRIZEPOOL
 * Verdict: Accepted
 * Submitted: 2026-06-07
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/PRIZEPOOL
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X, Y, R;
	cin >> T;
	
	for (int i = 0; i < T; i++){
	    cin >> X;
	    cin >> Y;
	    R = (X*10);
	    cout << R + 90*Y << endl;
	}
    return 0;
}
