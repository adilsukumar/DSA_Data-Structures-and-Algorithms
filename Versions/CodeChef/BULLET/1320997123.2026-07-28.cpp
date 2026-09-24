/*
 * Platform: CodeChef
 * Submission: 1320997123
 * Problem: BULLET
 * Verdict: Accepted
 * Submitted: 2026-07-28
 * Recorded in repository: 2026-09-24
 * Variant: Improved Approach 3 (inferred from submission order)
 * URL: https://www.codechef.com/problems/BULLET
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

    int T, X, Y, Z;

    cin >> T;

    

    for(int i = 0; i < T; i++){

        cin >> X >> Y >> Z;

        int seconds = Y/X;

        if(Z > seconds){

            cout << Z - seconds << endl;

        }

        else{

            cout << 0 << endl;

        }

    }

    return 0;

}

