/*
 * Platform: CodeChef
 * Submission: 1289387087
 * Problem: EXPERT
 * Verdict: partially accepted
 * Date: 2026-06-15
 * URL: https://www.codechef.com/problems/EXPERT
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
	    
	    if(Y >= X/2){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}

}
