/*
 * Platform: CodeChef
 * Submission: 1317589192
 * Problem: FCTRL2
 * Verdict: wrong answer
 * Date: 2026-07-26
 * URL: https://www.codechef.com/problems/FCTRL2
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t, n;
	cin >> t;
	
	for(int i = 0; i < t; i++){
	    cin >> n;
	    int fact = 1;
	    while(n >= 1){
	        fact *= n;
	        n--;
	    }
	    cout << fact << endl;
	}
    return 0;
}
