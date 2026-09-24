/*
 * Platform: CodeChef
 * Submission: 1293230591
 * Problem: TODOLIST
 * Verdict: Accepted
 * Submitted: 2026-06-23
 * Recorded in repository: 2026-09-24
 * Variant: Brute Force (inferred from submission order)
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

	    }

	    cout << count << endl;

	}

}

