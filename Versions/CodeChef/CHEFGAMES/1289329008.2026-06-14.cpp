/*
 * Platform: CodeChef
 * Submission: 1289329008
 * Problem: CHEFGAMES
 * Verdict: Accepted
 * Submitted: 2026-06-14
 * Recorded in repository: 2026-09-24
 * Variant: Improved Approach 10 (inferred from submission order)
 * URL: https://www.codechef.com/problems/CHEFGAMES
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, R1, R2, R3, R4;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> R1;

	    cin >> R2;

	    cin >> R3;

	    cin >> R4;

	    

	    if(R1 == 0 && R2 == 0 && R3 == 0 && R4 == 0){

	        cout << "IN" << endl;

	    }

	    else{

	        cout << "OUT" << endl;

	    }

	}

    return 0;

}

