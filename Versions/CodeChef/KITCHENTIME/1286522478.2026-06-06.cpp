/*
 * Platform: CodeChef
 * Submission: 1286522478
 * Problem: KITCHENTIME
 * Verdict: Accepted
 * Submitted: 2026-06-06
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/KITCHENTIME
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X, Y;
	cin >> T;
	for (int i = 0; i < T; i++){
	    cin >> X;
	    cin >> Y;
	    cout << Y-X << endl;
	}
	return 0;

}
