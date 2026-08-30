/*
 * Platform: CodeChef
 * Submission: 1294066360
 * Problem: ACTEMP
 * Verdict: wrong answer
 * Date: 2026-06-23
 * URL: https://www.codechef.com/problems/ACTEMP
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, A, B, C;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> A >> B >> C;
	    if(A <= C){
	        if(A <= C && A<B && C<B){
	            cout << "Yes" << endl;
	        }
	    }
	    if(C < A){
	        if(C < A && A<B && C<B){
	            cout << "No" << endl;
	        }
	    }
	}
    return 0;
}
