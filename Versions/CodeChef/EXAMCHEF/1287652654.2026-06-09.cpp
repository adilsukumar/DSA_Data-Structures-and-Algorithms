/*
 * Platform: CodeChef
 * Submission: 1287652654
 * Problem: EXAMCHEF
 * Verdict: Accepted
 * Submitted: 2026-06-09
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/EXAMCHEF
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X, Y, Z;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> X;
	    cin >> Y;
	    cin >> Z;
	    if(X*Y/2 < Z){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}
	return 0;

}
