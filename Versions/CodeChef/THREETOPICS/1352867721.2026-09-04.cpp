/*
 * Platform: CodeChef
 * Submission: 1352867721
 * Problem: THREETOPICS
 * Verdict: Accepted
 * Submitted: 2026-09-04
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/THREETOPICS
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int A,B,C,X;
	
    cin >> A >> B >> C >> X;
    if(X == A || X == B | X == C){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
	}
}
