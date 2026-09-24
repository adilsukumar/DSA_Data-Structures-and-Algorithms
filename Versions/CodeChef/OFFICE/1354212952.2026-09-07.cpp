/*
 * Platform: CodeChef
 * Submission: 1354212952
 * Problem: OFFICE
 * Verdict: Accepted
 * Submitted: 2026-09-07
 * Recorded in repository: 2026-09-24
 * Variant: Improved Approach 7 (inferred from submission order)
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
