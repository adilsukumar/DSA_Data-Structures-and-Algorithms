/*
 * Platform: CodeChef
 * Submission: 1288094434
 * Problem: BULLBEAR
 * Verdict: Accepted
 * Submitted: 2026-06-10
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/BULLBEAR
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X, Y;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> X;
	    cin >> Y;
	    if(Y>X){
	        cout << "PROFIT" << endl;
	    }
	    else if(X>Y){
	        cout << "LOSS"<< endl;
	    }
	    else{
	        cout << "NEUTRAL" << endl;
	    }
	}
	return 0;
}
