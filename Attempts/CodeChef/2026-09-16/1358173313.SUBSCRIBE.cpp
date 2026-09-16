/*
 * Platform: CodeChef
 * Submission: 1358173313
 * Problem: SUBSCRIBE
 * Verdict: wrong answer
 * Date: 2026-09-16
 * URL: https://www.codechef.com/problems/SUBSCRIBE
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> X;
	    if(X <= 30){
	        cout << "YES\n";
	    }
	    else{
	        cout << "NO\n";
	    }
	}
	return 0;
}
