/*
 * Platform: CodeChef
 * Submission: 1310812716
 * Problem: MAXTASTE
 * Verdict: compilation error
 * Date: 2026-07-19
 * URL: https://www.codechef.com/problems/MAXTASTE
 *  */

#include <bits/stdc++.h>
using namespace std;

(int main() {
	// your code goes here
	int T, A, B, C, D;
	cin >> T;
	
	for(int i = 0; i < T; ++){
	    cin >> A >> B >> C >> D;
	    if(A >= B){
	        if(C >= D){
	            cout << A+C << endl;
	        }
	        else{
	            cout << A+D << endl;
	        }
	    }
	    else if(B >= A){
	        if(C >= D){
	            cout << B+C << endl;
	        }
	        else{
	            cout << B+D << endl;
	        }
	    }
	}
	return 0;
}
