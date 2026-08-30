/*
 * Platform: CodeChef
 * Submission: 1286869989
 * Problem: SUBSCRIBE_
 * Verdict: wrong answer
 * Date: 2026-06-08
 * URL: https://www.codechef.com/problems/SUBSCRIBE_
 *  */

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	int T, N, X;
	for (int i = 0; i < T; i++){
	    cin >> N;
	    cin >> X;
	    if (N%6 == 0){
	        cout << X * (N/6) << endl;
	    }
	    else{
	        cout << X * ceil(N/6) << endl;
	    }
	}
}
