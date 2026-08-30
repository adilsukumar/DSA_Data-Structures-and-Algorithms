/*
 * Platform: CodeChef
 * Submission: 1314411152
 * Problem: BATH
 * Verdict: compilation error
 * Date: 2026-07-22
 * URL: https://www.codechef.com/problems/BATH
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X, Y;
	cin >> T;
	
	for(int i : T){
	    cin >> X >> Y;
	    if(2*Y > X){
	        cout << 0 << endl;
	    }
	    else{
	        cout << ceil(X%2);
	    }
	}
	return 0;
}
