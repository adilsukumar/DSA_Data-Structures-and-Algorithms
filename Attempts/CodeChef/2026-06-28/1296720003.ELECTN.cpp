/*
 * Platform: CodeChef
 * Submission: 1296720003
 * Problem: ELECTN
 * Verdict: compilation error
 * Date: 2026-06-28
 * URL: https://www.codechef.com/problems/ELECTN
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, X;
	cin >> T;
	int count = 0;
	
	for(int i = 0; i < T; i++){
	    cin >> N >> X;
	    int Z;
	    for(int j = 0; j < Z; j++){
	        cin >> Z;
	        for(int z = 0; z < Z, z++){
	            if (z > X){
	                count += 1;
	            }
	        }
	    }
	}
    return count
}
