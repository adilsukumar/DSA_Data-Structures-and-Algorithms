/*
 * Platform: CodeChef
 * Submission: 1286584809
 * Problem: CANDIVIDE
 * Verdict: Accepted
 * Submitted: 2026-06-07
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/CANDIVIDE
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N;
	cin >> T;
	
	for (int i = 0; i < T; i++){
	    cin >> N;
	    if (N%3 == 0){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}

}
