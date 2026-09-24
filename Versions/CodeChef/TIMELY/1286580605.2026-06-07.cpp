/*
 * Platform: CodeChef
 * Submission: 1286580605
 * Problem: TIMELY
 * Verdict: Accepted
 * Submitted: 2026-06-07
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/TIMELY
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X;
	cin >> T;
	for (int i = 0; i < T; i++){
	    cin >> X;
	    if (X >= 30){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}
    return 0;
}
