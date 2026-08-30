/*
 * Platform: CodeChef
 * Submission: 1293230258
 * Problem: TODOLIST
 * Verdict: wrong answer
 * Date: 2026-06-23
 * URL: https://www.codechef.com/problems/TODOLIST
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, D, count;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> N;
	    for(int j = 0; j < N; j++){
	        cin >> D;
	        
	        if(D >= 1000){
	            count = 0;
	            count += 1;
	        }
	    }
	}
	cout << count << endl;
}
