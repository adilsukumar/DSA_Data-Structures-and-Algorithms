/*
 * Platform: CodeChef
 * Submission: 1286585159
 * Problem: PAR2
 * Verdict: Accepted
 * Submitted: 2026-06-07
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/PAR2
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N;
	cin >> T;
	
	for (int i = 0; i < T; i++){
	    cin >> N;
	    if(N%2 == 0){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}
    return 0;
}
