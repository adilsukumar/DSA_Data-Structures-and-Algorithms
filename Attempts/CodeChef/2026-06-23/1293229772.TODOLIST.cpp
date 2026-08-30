/*
 * Platform: CodeChef
 * Submission: 1293229772
 * Problem: TODOLIST
 * Verdict: compilation error
 * Date: 2026-06-23
 * URL: https://www.codechef.com/problems/TODOLIST
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, D, count;
	cin >> T;
	count = 0;
	
	for(int i = 0; i < T; i++){
	    cin >> N;
	    for(int j = 0; j < N; j++){
	        cin >> D;
	        if(D[i][j] >= 1000){
	            count += 1;
	        }
	    }
	}
	return count;
}
