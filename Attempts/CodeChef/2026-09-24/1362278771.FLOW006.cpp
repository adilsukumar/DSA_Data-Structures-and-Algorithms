/*
 * Platform: CodeChef
 * Submission: 1362278771
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
	string s = to_string(N);
	cin >> T;
	for(int i = 0; i < T; i++){
	    cin >> N;
	    for(int j = 0; j < s.size(); j++){
	        sum += s[j]-0; 
	    }
	    cout << sum << "\n";
	}
	return 0;

}
