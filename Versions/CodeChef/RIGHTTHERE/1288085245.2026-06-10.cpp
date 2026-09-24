/*
 * Platform: CodeChef
 * Submission: 1288085245
 * Problem: RIGHTTHERE
 * Verdict: Accepted
 * Submitted: 2026-06-10
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/RIGHTTHERE
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, X;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> N;
	    cin >> X;
	    if(N <= X){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}
    return 0;
}
