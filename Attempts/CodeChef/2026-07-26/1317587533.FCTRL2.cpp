/*
 * Platform: CodeChef
 * Submission: 1317587533
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
	    while(n >= 1){
	        fact *= n;
	        n--;
	    }
	    cout << fact << endl;
	}
    return 0;
}
