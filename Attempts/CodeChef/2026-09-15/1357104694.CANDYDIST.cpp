/*
 * Platform: CodeChef
 * Submission: 1357104694
 * Problem: CANDYDIST
 * Verdict: partially accepted
 * Date: 2026-09-15
 * URL: https://www.codechef.com/problems/CANDYDIST
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, M;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> N >> M;
	    if(N%2 == 0){
	        cout << "Yes\n";
	    }
	    else{
	        cout << "No\n";
	    }
	}
	return 0;
}
