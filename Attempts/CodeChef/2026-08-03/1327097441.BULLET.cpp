/*
 * Platform: CodeChef
 * Submission: 1327097441
 * Problem: BULLET
 * Verdict: wrong answer
 * Date: 2026-08-03
 * URL: https://www.codechef.com/problems/BULLET
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, X, Y, Z;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> X >> Y >> Z;
	    int seconds_taken = Y/X;
	    cout << Z - seconds_taken << endl;
	}
}
