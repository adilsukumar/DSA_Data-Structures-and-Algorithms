/*
 * Platform: CodeChef
 * Submission: 1297254276
 * Problem: MINCARS
 * Verdict: wrong answer
 * Date: 2026-06-30
 * URL: https://www.codechef.com/problems/MINCARS
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> N;
	    if(N <= 4){
	        cout << 1 << endl;
	    }
	    else{
	        cout << N/4 << endl;
	    }
	}

}
