/*
 * Platform: CodeChef
 * Submission: 1352096242
 * Problem: DNASTRAND
 * Verdict: Accepted
 * Submitted: 2026-09-02
 * Recorded in repository: 2026-09-24
 * Variant: Optimized (inferred from submission order)
 * URL: https://www.codechef.com/problems/DNASTRAND
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N;
	string S;
	
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> N >> S;
	    for(int j = 0; j < S.length(); j++){
	        if(S[j] == 'A'){
	            cout << 'T';
	        }
	        else if(S[j] == 'T'){
	            cout << 'A';
	        }
	        else if(S[j] == 'G'){
	            cout << 'C';
	        }
	        else{
	            cout << 'G';
	        }
	    }
	    cout << endl;
	}
    return 0;
}
