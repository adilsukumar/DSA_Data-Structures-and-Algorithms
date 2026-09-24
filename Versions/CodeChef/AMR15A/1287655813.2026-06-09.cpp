/*
 * Platform: CodeChef
 * Submission: 1287655813
 * Problem: AMR15A
 * Verdict: Accepted
 * Submitted: 2026-06-09
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/AMR15A
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int N, X;
	int even_no = 0;
	int odd_no = 0;
	cin >> N;
	for(int i = 0; i < N; i++){
	    cin >> X;
	    if(X%2 == 0){
	        even_no++;
	    }
	    else{
	        odd_no++;
	    }
	}
	if(even_no > odd_no){
	    cout << "READY FOR BATTLE";
	}
	else{
	    cout << "NOT READY";
	}
	return 0;
}
