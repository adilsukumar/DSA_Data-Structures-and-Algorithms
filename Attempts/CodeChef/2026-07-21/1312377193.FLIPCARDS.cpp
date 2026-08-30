/*
 * Platform: CodeChef
 * Submission: 1312377193
 * Problem: FLIPCARDS
 * Verdict: wrong answer
 * Date: 2026-07-21
 * URL: https://www.codechef.com/problems/FLIPCARDS
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, X;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> N >> X;
	    if(X >= N-X){
	        cout << N-X << endl;
	    }
	    else{
	        cout << N << endl;
	    }
	}
}
