/*
 * Platform: CodeChef
 * Submission: 1317565109
 * Problem: FINDSHOES
 * Verdict: Accepted
 * Submitted: 2026-07-25
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/FINDSHOES
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, M;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> N >> M;
	    if(N >= M){
	        cout << N-M + N << endl;
	    }
	    else{
	        cout << N << endl;
	    }
	}
	return 0;
}
