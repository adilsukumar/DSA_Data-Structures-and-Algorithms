/*
 * Platform: CodeChef
 * Submission: 1356161915
 * Problem: CREDCOINS
 * Verdict: Accepted
 * Submitted: 2026-09-11
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/CREDCOINS
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
	    
	    if(X*Y >= 100){
	        cout << (X*Y)/100 << endl;
	    }
	    else{
	        cout << 0 << endl;
	    }
	}
    return 0;   
}
