/*
 * Platform: CodeChef
 * Submission: 1288091877
 * Problem: SNDMAX
 * Verdict: wrong answer
 * Date: 2026-06-10
 * URL: https://www.codechef.com/problems/SNDMAX
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, A, B, C;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> A;
	    cin >> B;
	    cin >> C;
	    if(C < A && A < B){
	        cout << A << endl;
	    }
	    else if (C < B && B < A){
	        cout << B << endl;
	    }
	    else{
	        cout << C << endl;
	    }
	}
}
