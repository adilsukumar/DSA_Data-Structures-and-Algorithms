/*
 * Platform: CodeChef
 * Submission: 1362275116
 * Problem: FLOW006
 * Verdict: wrong answer
 * Date: 2026-09-24
 * URL: https://www.codechef.com/problems/FLOW006
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, sum;
	cin >> T;
	for(int i = 0; i < T; i++){
	    cin >> N;
	    for(int j = 0; j < to_string(N).size(); j++){
	        sum += j-0; 
	    }
	    cout << sum << "\n";
	}
	return 0;

}
