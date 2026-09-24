/*
 * Platform: CodeChef
 * Submission: 1286077956
 * Problem: TOP10
 * Verdict: Accepted
 * Submitted: 2026-06-05
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/TOP10
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X;
	cin >> T;
	
	for(int i = 1; i <= T; i++){
	    cin >> X;
	    if(X <= 10){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}

}
