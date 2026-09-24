/*
 * Platform: CodeChef
 * Submission: 1290046843
 * Problem: HELIUM3
 * Verdict: Accepted
 * Submitted: 2026-06-16
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/HELIUM3
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, A, B, X, Y;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> A >> B >> X >> Y;
	    if(X*Y >= A*B){
	        cout << "Yes" << endl;
	    }
	    else{
	        cout << "No" << endl;
	    }
	}

}
