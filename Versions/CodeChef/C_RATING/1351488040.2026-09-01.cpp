/*
 * Platform: CodeChef
 * Submission: 1351488040
 * Problem: C_RATING
 * Verdict: Accepted
 * Submitted: 2026-09-01
 * Recorded in repository: 2026-09-24
 * Variant: Improved Approach 6 (inferred from submission order)
 * URL: https://www.codechef.com/problems/C_RATING
 *  */

#include <bits/stdc++.h>

using namespace std;



int main() {

    int T, X, Y;

    cin >> T;



    for(int i = 0; i < T; i++) {

        cin >> X >> Y;



        int remaining = Y - X;



        cout << (remaining + 7) / 8 << endl;

    }



    return 0;

}