/*
 * Platform: CodeChef
 * Submission: 1352107042
 * Problem: CHEFBOTTLE
 * Verdict: wrong answer
 * Date: 2026-09-02
 * URL: https://www.codechef.com/problems/CHEFBOTTLE
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, X, K;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> N >> X >> K;
	    if(N*X >= K){
	        if(X < K){
	            cout << K - X << endl;
	        }
	        else{
	            cout << 0 << endl;
	        }
	    }
	    else{
	        cout << N << endl;
	    }
	}
	return 0;
}
