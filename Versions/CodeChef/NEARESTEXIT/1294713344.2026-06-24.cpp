/*
 * Platform: CodeChef
 * Submission: 1294713344
 * Problem: NEARESTEXIT
 * Verdict: Accepted
 * Submitted: 2026-06-24
 * Recorded in repository: 2026-09-24
 * Variant: Brute Force (inferred from submission order)
 * URL: https://www.codechef.com/problems/NEARESTEXIT
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

    int T, X;

    cin >> T;

    

    for(int i = 0; i < T; i++){

        cin >> X;

        if(X <= 50){

            cout << "LEFT" << endl;

        }

        else{

            cout << "RIGHT" << endl;

        }

    }

    return 0;

}

