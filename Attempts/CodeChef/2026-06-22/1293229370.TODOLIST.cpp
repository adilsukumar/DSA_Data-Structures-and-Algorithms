/*
 * Platform: CodeChef
 * Submission: 1293229370
 * Problem: TODOLIST
 * Verdict: compilation error
 * Date: 2026-06-22
 * URL: https://www.codechef.com/problems/TODOLIST
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, D, count, j;
	cin >> T;
	count = 0;
	
	for(int i = 0; i < T; i++){
	    cin >> N;
	    for(j = 0; j < N; j++){
	        cin >> D;
	    }
	    if(D[j] >= 1000){
	        count += 1;
	    }
	}
	return count;
}
