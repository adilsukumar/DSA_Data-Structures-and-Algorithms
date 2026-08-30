/*
 * Platform: CodeChef
 * Submission: 1317580561
 * Problem: FCTRL2
 * Verdict: wrong answer
 * Date: 2026-07-26
 * URL: https://www.codechef.com/problems/FCTRL2
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t,n;
	int factorial = 1;
	cin >> t;
	
	while(t--){
	    cin >> n;
	    for(int i = 1; i <= n; i++){
	        factorial *= n*i;
	    }
	    cout << factorial;
	}
	return 0;
}
