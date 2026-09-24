/*
 * Platform: CodeChef
 * Submission: 1286585755
 * Problem: AVGPROBLEM
 * Verdict: Accepted
 * Submitted: 2026-06-07
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/AVGPROBLEM
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
	    if ((A+B) > 2*C){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}
    return 0;
}
