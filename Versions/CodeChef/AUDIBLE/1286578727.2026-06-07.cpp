/*
 * Platform: CodeChef
 * Submission: 1286578727
 * Problem: AUDIBLE
 * Verdict: Accepted
 * Submitted: 2026-06-07
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/AUDIBLE
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X;
	cin >> T;
	for (int i = 0; i < T; i++){
	    cin >> X;
	    if (X >= 67 && X <= 45000){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}
	return 0;
}
