/*
 * Platform: CodeChef
 * Submission: 1294068124
 * Problem: ACTEMP
 * Verdict: wrong answer
 * Date: 2026-06-23
 * URL: https://www.codechef.com/problems/ACTEMP
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, A, B, C;
	cin >> T;
	
	if (max(A,C) <= B){
	    cout << "Yes" << endl;
	}
	else{
	    cout << "No" << endl;
	}
    return 0;
}
