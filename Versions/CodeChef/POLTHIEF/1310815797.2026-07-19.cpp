/*
 * Platform: CodeChef
 * Submission: 1310815797
 * Problem: POLTHIEF
 * Verdict: Accepted
 * Submitted: 2026-07-19
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/POLTHIEF
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X, Y;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> X >> Y;
	    if(X >= Y){
	        cout << X-Y << endl;
	    }
	    else{
	        cout << Y-X << endl;
	    }
	}
	return 0;
}
