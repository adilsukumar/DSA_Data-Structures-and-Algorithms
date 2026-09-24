/*
 * Platform: CodeChef
 * Submission: 1297664981
 * Problem: CHEFSCORE
 * Verdict: Accepted
 * Submitted: 2026-06-30
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/CHEFSCORE
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, X, Y;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> N >> X >> Y;
	    if(N*X >= Y && Y%X == 0){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	    
	}

}
