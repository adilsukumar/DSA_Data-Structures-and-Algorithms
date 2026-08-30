/*
 * Platform: CodeChef
 * Submission: 1310815597
 * Problem: POLTHIEF
 * Verdict: wrong answer
 * Date: 2026-07-19
 * URL: https://www.codechef.com/problems/POLTHIEF
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X, Y;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> X >> Y;
	    cout << X-Y << endl;
	}
	return 0;
}
