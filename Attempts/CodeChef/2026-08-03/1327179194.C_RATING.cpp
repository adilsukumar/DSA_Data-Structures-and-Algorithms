/*
 * Platform: CodeChef
 * Submission: 1327179194
 * Problem: C_RATING
 * Verdict: wrong answer
 * Date: 2026-08-03
 * URL: https://www.codechef.com/problems/C_RATING
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X, Y;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> X >> Y;
	    if(X == Y){
	        cout << 0 << endl;
	    }
	    else{
	        int remaining = Y-X;
	        if(remaining <= 8){
	            cout << 1 << endl;
	        }
	        else{
	            cout << Y % 8 << endl;
	        }
	    }
	}
	return 0;
}
