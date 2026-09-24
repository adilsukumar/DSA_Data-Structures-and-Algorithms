/*
 * Platform: CodeChef
 * Submission: 1287658526
 * Problem: CREDCOINS
 * Verdict: Accepted
 * Submitted: 2026-06-10
 * Recorded in repository: 2026-09-24
 * Variant: Brute Force (inferred from submission order)
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
