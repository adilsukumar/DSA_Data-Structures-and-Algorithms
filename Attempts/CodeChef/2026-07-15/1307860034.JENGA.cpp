/*
 * Platform: CodeChef
 * Submission: 1307860034
 * Problem: JENGA
 * Verdict: partially accepted
 * Date: 2026-07-15
 * URL: https://www.codechef.com/problems/JENGA
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, X;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> N >> X;
	    if(X >= N){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}
    return 0;
}
