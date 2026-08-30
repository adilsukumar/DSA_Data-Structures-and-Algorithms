/*
 * Platform: CodeChef
 * Submission: 1296721401
 * Problem: ELECTN
 * Verdict: compilation error
 * Date: 2026-06-28
 * URL: https://www.codechef.com/problems/ELECTN
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, X, Z;
	cin >> T;
	int count = 0;
	
	for(int i = 0; i < T; i++){
	    cin >> N >> X;
	    for(int j = 0; j < N; j++){
	        cin >> Z;
	        for(int z = 0; z < Z; z++){
	            if (Z[z] >= X){
	                count += 1;
	            }
	        }
	    }
	}
    return count;
}
