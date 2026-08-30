/*
 * Platform: CodeChef
 * Submission: 1314388673
 * Problem: FLIPCARDS
 * Verdict: wrong answer
 * Date: 2026-07-22
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
	    if(X > N-X){
	        cout << N-X << endl;
	    }
	    else if(X == N){
	        cout << "0" << endl;
	    }
	    else{
	        cout << N << endl;
	    }
	}
	return 0;
}
