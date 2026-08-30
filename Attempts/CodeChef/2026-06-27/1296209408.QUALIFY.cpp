/*
 * Platform: CodeChef
 * Submission: 1296209408
 * Problem: QUALIFY
 * Verdict: wrong answer
 * Date: 2026-06-27
 * URL: https://www.codechef.com/problems/QUALIFY
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X, A, B;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> X >> A >> B;
	    if((A*1 + B*2) >= X){
	        cout << "Quallify" << endl;
	    }
	    else{
	        cout << "NotQualify" << endl;
	    }
	}
}