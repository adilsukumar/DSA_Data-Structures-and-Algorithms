/*
 * Platform: CodeChef
 * Submission: 1286584681
 * Problem: MINHEIGHT
 * Verdict: Accepted
 * Submitted: 2026-06-07
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/MINHEIGHT
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X, H;
	cin >> T;
	
	for (int i = 0; i < T; i++){
	    cin >> X;
	    cin >> H;
	    if(X >= H){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}
}
