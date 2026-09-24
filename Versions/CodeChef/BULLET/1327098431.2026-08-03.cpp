/*
 * Platform: CodeChef
 * Submission: 1327098431
 * Problem: BULLET
 * Verdict: Accepted
 * Submitted: 2026-08-03
 * Recorded in repository: 2026-09-24
 * Variant: Optimized (inferred from submission order)
 * URL: https://www.codechef.com/problems/BULLET
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X, Y, Z;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> X >> Y >> Z;
	    int seconds_taken = Y/X;
	    if(seconds_taken > Z){
	        cout << 0 << endl;
	    }
	    else{
	        cout << Z - seconds_taken << endl;
	    }
	}
	return 0;
}
