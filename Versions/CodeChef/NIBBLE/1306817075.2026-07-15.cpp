/*
 * Platform: CodeChef
 * Submission: 1306817075
 * Problem: NIBBLE
 * Verdict: Accepted
 * Submitted: 2026-07-15
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/NIBBLE
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> X;
	    if(X%4 == 0){
	        cout << "Good" << endl;
	    }
	    else{
	        cout << "Not Good" << endl;
	    }
	}
	return 0;
}
