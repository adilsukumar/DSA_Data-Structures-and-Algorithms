/*
 * Platform: CodeChef
 * Submission: 1364755147
 * Problem: EZSPEAK
 * Verdict: Accepted
 * Submitted: Unknown-Date
 * Recorded in repository: 2026-09-29
 * Variant: Brute Force (inferred from submission order)
 * URL: https://www.codechef.com/problems/EZSPEAK
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N;

	string S;

	cin >> T;

	for(int i = 0; i < T; i++){

	    int consecutive = 0;

	    bool xyz = false;

	    cin >> N;

	    cin >> S;

	    for(int j = 0; j < N; j++){

	        if(S[j] != 'a' && S[j] != 'e' && S[j] != 'i' && S[j] != 'o' && S[j] != 'u'){

	            consecutive++;

	            if(consecutive >= 4){

	                xyz = true;

	            }

	        }

	        else{

	            consecutive=0;

	        }

	    }

	    if(xyz){

	        cout << "NO" << endl;

	    }

	    else{

	        cout << "YES" << endl;

	    }

	}

}

