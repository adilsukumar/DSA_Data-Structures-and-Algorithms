/*
 * Platform: CodeChef
 * Submission: 1352094392
 * Problem: DNASTRAND
 * Verdict: compilation error
 * Date: 2026-09-02
 * URL: https://www.codechef.com/problems/DNASTRAND
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, S;
	
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> N >> S;
	    for(int j = 0; j < S.size(); j++){
	        if(S[j] == "A"){
	            cout << "T";
	        }
	        else if(S[j] == "T"){
	            cout << "A";
	        }
	        else if(S[j] == "G"){
	            cout << "S";
	        }
	        else{
	            cout << "G";
	        }
	    }
	    cout << endl;
	}
    return 0;
}
