/*
 * Platform: CodeChef
 * Submission: 1293230551
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
	    count = 0;
	    for(int j = 0; j < N; j++){
	        cin >> D;
	        if(D >= 1000){
	            count += 1;
	        }
	    cout << count << endl;
	    }
	}
}
