/*
 * Platform: CodeChef
 * Submission: 1317596872
 * Problem: FLIPCARDS
 * Verdict: wrong answer
 * Date: 2026-07-26
 * URL: https://www.codechef.com/problems/FLIPCARDS
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, X;
	cin >> T;
	
	while(T--){
	    if(N == X || X == 0){
	        cout << 0 << endl;
	    }
	    else{
	        if(N >= 2*X){
	            cout << X << endl;
	        }
	        else{
	            cout << N-X << endl;
	        }
	    }
	}
	return 0;
}
