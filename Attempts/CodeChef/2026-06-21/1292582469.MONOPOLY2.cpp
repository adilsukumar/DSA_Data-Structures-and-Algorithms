/*
 * Platform: CodeChef
 * Submission: 1292582469
 * Problem: MONOPOLY2
 * Verdict: wrong answer
 * Date: 2026-06-21
 * URL: https://www.codechef.com/problems/MONOPOLY2
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, P, Q, R, S;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> P >> Q >> R >> S;
	    if(P <= (Q+R+S) || Q <= (P+R+S) || R <= (P+Q+S) || S <= (P+Q+R)){
	        cout << "NO" << endl;
	    }
	    else{
	        cout << "YES" << endl;
	    }
	}
    return 0;
}
