/*
 * Platform: CodeChef
 * Submission: 1286584327
 * Problem: BESTOFTWO
 * Verdict: wrong answer
 * Date: 2026-06-07
 * URL: https://www.codechef.com/problems/BESTOFTWO
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X, Y;
	cin >> T;
	
	for (int i = 0; i < T; i++){
	    cin >> X;
	    cin >> Y;
	    if(X>Y){
	        cout << X;
	    }
	    else{
	        cout << Y;
	    }
	}
    return 0;
}
