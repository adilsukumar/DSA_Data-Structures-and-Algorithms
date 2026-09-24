/*
 * Platform: CodeChef
 * Submission: 1287660958
 * Problem: SALESEASON
 * Verdict: Accepted
 * Submitted: 2026-06-10
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/SALESEASON
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> X;
	    if(X <= 100){
	        cout << X << endl;
	    }
	    else if(X > 100 && X <= 1000){
	        cout << X-25 << endl;
	    }
	    else if(X > 1000 && X <= 5000){
	        cout << X-100 << endl;
	    }
	    else{
	        cout << X-500 << endl;
	    }
	}
    return 0;
}
