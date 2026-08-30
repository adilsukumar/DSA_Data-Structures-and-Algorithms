/*
 * Platform: CodeChef
 * Submission: 1317586316
 * Problem: FCTRL2
 * Verdict: wrong answer
 * Date: 2026-07-26
 * URL: https://www.codechef.com/problems/FCTRL2
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t, n, fact;
	cin >> t;
	for(int i = 0; i < t; i++){
	    cin >> n;
	    if(n == 0){
	        fact = 1;
	    }
	    else{
	        for(int j = 1; j < n; j++){
	            fact = n*i;
	        }
	    }
	    cout << fact << endl;
	}
	return 0;
}
