/*
 * Platform: CodeChef
 * Submission: 1290544660
 * Problem: CHEFCAND
 * Verdict: Accepted
 * Submitted: 2026-06-17
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/CHEFCAND
 *  */

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	int T, N, X, a;
	cin >> T;
	for(int i = 0; i < T; i++){
	    cin >> N >> X;
	    if((N-X) > 0){
	        a = N-X;
	        cout << ceil(a / 4.0) << endl;
	    }
	    else{
	        cout << 0 << endl;
	    }
	}
	return 0;

}
