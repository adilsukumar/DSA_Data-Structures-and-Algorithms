/*
 * Platform: CodeChef
 * Submission: 1319696343
 * Problem: TRANSFORM
 * Verdict: wrong answer
 * Date: 2026-07-27
 * URL: https://www.codechef.com/problems/TRANSFORM
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> X;
	    if(X%3 == 1){
	        cout << "SMALL" << endl;
	    }
	    else if(X%3 == 0){
	        cout << "NORMAL" << endl;
	    }
	    else{
	        cout << "HUGE" << endl;
	    }
	}
	return 0;
}
