/*
 * Platform: CodeChef
 * Submission: 1362279150
 * Problem: FLOW006
 * Verdict: Accepted
 * Submitted: 2026-09-24
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/FLOW006
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N;
	cin >> T;
	for(int i = 0; i < T; i++){
	    cin >> N;
	    int sum = 0;
	    string s = to_string(N);
	    for(int j = 0; j < s.size(); j++){
	        sum += s[j]-'0'; 
	    }
	    cout << sum << "\n";
	}
	return 0;

}
