/*
 * Platform: CodeChef
 * Submission: 1317588504
 * Problem: FCTRL2
 * Verdict: compilation error
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
	    fact = 1;
	    while(n >= 1){
	        fact *= n;
	        n--;
	    }
	    cout << fact << endl;
	}
    return 0;
}
