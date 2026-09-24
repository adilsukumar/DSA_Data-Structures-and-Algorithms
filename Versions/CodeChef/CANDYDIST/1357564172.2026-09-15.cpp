/*
 * Platform: CodeChef
 * Submission: 1357564172
 * Problem: CANDYDIST
 * Verdict: Accepted
 * Submitted: 2026-09-15
 * Recorded in repository: 2026-09-24
 * Variant: Improved Approach 1 (inferred from submission order)
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
	    if(N%M == 0 && (N / M) % 2 == 0){
	        cout << "Yes\n";
	    }
	    else{
	        cout << "No\n";
	    }
	}
	return 0;
}
