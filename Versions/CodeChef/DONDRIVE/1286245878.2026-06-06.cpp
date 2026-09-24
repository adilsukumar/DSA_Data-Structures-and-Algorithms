/*
 * Platform: CodeChef
 * Submission: 1286245878
 * Problem: DONDRIVE
 * Verdict: Accepted
 * Submitted: 2026-06-06
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/DONDRIVE
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, X;
	cin >> T;
	
	for (int i = 0; i < T; i++){
	    cin >> N;
	    cin >> X;
	    cout << N-X << endl;
	}
	return 0;

}
