/*
 * Platform: CodeChef
 * Submission: 1286585403
 * Problem: AVGPROBLEM
 * Verdict: wrong answer
 * Date: 2026-06-07
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
	    if ((A+B)/2 == C){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}
    return 0;
}
