/*
 * Platform: CodeChef
 * Submission: 1310811688
 * Problem: DISCUS
 * Verdict: Accepted
 * Submitted: 2026-07-19
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/DISCUS
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, A, B, C;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> A >> B >> C;
	    if(A >= B && A >= C){
	        cout << A << endl;
	    }
	    else if(B >= A && B >= C){
	        cout << B << endl;
	    }
	    else{
	        cout << C << endl;
	    }
	}
	return 0;
}
