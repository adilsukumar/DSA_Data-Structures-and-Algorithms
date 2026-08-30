/*
 * Platform: CodeChef
 * Submission: 1290544629
 * Problem: CHEFCAND
 * Verdict: wrong answer
 * Date: 2026-06-17
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
	        cout << ceil(a / 4.0);
	    }
	    else{
	        cout << 0;
	    }
	}
	return 0;

}
