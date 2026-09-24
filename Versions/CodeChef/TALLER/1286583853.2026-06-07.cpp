/*
 * Platform: CodeChef
 * Submission: 1286583853
 * Problem: TALLER
 * Verdict: Accepted
 * Submitted: 2026-06-07
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/TALLER
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
	    if(X>Y){
	        cout << "A" << endl;
	    }
	    else{
	        cout << "B" << endl;
	    }
	}
	return 0;
}
