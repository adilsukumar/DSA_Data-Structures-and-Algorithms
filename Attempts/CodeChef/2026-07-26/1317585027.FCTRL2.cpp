/*
 * Platform: CodeChef
 * Submission: 1317585027
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
	
	while(t--){
	    cin >> n;
	    if(n == 1){
	        cout << 1 << endl;
	    }
	    else{
	        for(int i = 1; i <= n; i++){
	        fact = n*i;
	        }
	        cout << fact << endl;
	    }
	}
	return 0;
}
