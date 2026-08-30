/*
 * Platform: CodeChef
 * Submission: 1317556984
 * Problem: FINDSHOES
 * Verdict: wrong answer
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
	    if(M < N){
	        cout << (M+M) + (N-M) << endl;
	    }
	    else if(M == 0){
	        cout << N*2 << endl;
	    }
	    else{
	        cout << (N-M) << endl;
	    }
	}
	return 0;
}
