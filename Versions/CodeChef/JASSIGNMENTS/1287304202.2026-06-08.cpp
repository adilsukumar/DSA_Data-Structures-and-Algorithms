/*
 * Platform: CodeChef
 * Submission: 1287304202
 * Problem: JASSIGNMENTS
 * Verdict: Accepted
 * Submitted: 2026-06-08
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/JASSIGNMENTS
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T,X;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> X;
	    if(X > 7){
	        cout << "No" << endl;
	    }
	    else{
	        cout << "Yes" << endl;
	    }
	}

}
