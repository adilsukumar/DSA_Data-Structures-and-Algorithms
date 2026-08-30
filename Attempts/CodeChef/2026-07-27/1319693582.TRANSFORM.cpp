/*
 * Platform: CodeChef
 * Submission: 1319693582
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
	
	for(int i = 1; i < T; i++){
	    cin >> X;
	    if(X%2 == 0){
	        cout << "small" << endl;
	    }
	    else if(X%3 == 0){
	        cout << "normal" << endl;
	    }
	    else{
	        cout << "huge" << endl;
	    }
	}
	return 0;
}
