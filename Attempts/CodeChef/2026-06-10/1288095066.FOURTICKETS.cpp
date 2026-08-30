/*
 * Platform: CodeChef
 * Submission: 1288095066
 * Problem: FOURTICKETS
 * Verdict: wrong answer
 * Date: 2026-06-10
 * URL: https://www.codechef.com/problems/FOURTICKETS
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> X;
	    if(X*4 == 1000){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}
	return 0;
}
