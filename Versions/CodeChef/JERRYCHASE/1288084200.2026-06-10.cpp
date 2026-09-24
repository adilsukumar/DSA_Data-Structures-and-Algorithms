/*
 * Platform: CodeChef
 * Submission: 1288084200
 * Problem: JERRYCHASE
 * Verdict: Accepted
 * Submitted: 2026-06-10
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/JERRYCHASE
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
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}
	return 0;
}
