/*
 * Platform: CodeChef
 * Submission: 1286573002
 * Problem: IPLTRSH
 * Verdict: Accepted
 * Submitted: 2026-06-07
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/IPLTRSH
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, M;
	cin >> T;
	for (int i = 0; i < T; i++){
	    cin >> N;
	    cin >> M;
	    if (N > M){
	        cout << N-M << endl;
	    }
	    else{
	        cout << 0 << endl;
	    }
	}

}
