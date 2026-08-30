/*
 * Platform: CodeChef
 * Submission: 1286580484
 * Problem: TIMELY
 * Verdict: wrong answer
 * Date: 2026-06-07
 * URL: https://www.codechef.com/problems/TIMELY
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X;
	cin >> T;
	for (int i = 0; i < T; i++){
	    cin >> X;
	    if (X <= 30){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}
    return 0;
}
