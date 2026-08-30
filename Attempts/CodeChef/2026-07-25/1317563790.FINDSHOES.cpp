/*
 * Platform: CodeChef
 * Submission: 1317563790
 * Problem: FINDSHOES
 * Verdict: partially accepted
 * Date: 2026-07-25
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
	        cout << M - N << endl;
	    }
	}
	return 0;
}
