/*
 * Platform: CodeChef
 * Submission: 1358173556
 * Problem: SUBSCRIBE
 * Verdict: Accepted
 * Submitted: 2026-09-16
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/SUBSCRIBE
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> X;
	    if(X <= 30){
	        cout << "NO\n";
	    }
	    else{
	        cout << "YES\n";
	    }
	}
	return 0;
}
