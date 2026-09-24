/*
 * Platform: CodeChef
 * Submission: 1296723236
 * Problem: ELECTN
 * Verdict: Accepted
 * Submitted: 2026-06-28
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/ELECTN
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, X, Z;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    int count = 0;
	    cin >> N >> X;
	    for(int j = 0; j < N; j++){
	        cin >> Z;
            if (Z >= X){
                count ++;
            }
	    }
    cout << count << endl;
	}
}
