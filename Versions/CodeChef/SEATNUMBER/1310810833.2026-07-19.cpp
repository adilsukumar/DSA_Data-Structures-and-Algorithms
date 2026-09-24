/*
 * Platform: CodeChef
 * Submission: 1310810833
 * Problem: SEATNUMBER
 * Verdict: Accepted
 * Submitted: 2026-07-19
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/SEATNUMBER
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes 
	int N, T;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> N;
	    if(N <= 10){
	        cout << "Lower Double" << endl;
	    }
	    else if(N >= 10 && N <= 15){
	        cout << "Lower Single" << endl;
	    }
	    else if(N >= 16 && N <= 25){
	        cout << "Upper Double" << endl;
	    }
	    else{
	        cout << "Upper Single" << endl;
	    }
	}
    return 0;
}
