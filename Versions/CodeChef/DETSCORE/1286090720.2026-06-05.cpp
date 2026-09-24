/*
 * Platform: CodeChef
 * Submission: 1286090720
 * Problem: DETSCORE
 * Verdict: Accepted
 * Submitted: 2026-06-05
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/DETSCORE
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int TG, T, X, N;
	TG = 10;
	cin >> T;
	for(int i = 0; i < T; i++){
	    cin >> X;
	    cin >> N;
	    cout << (X/TG) * N << endl;
	}
	return 0;
}
