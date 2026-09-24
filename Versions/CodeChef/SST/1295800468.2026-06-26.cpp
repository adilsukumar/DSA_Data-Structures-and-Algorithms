/*
 * Platform: CodeChef
 * Submission: 1295800468
 * Problem: SST
 * Verdict: Accepted
 * Submitted: 2026-06-26
 * Recorded in repository: 2026-09-24
 * Variant: Improved Approach 4 (inferred from submission order)
 * URL: https://www.codechef.com/problems/SST
 *  */

#include <iostream>

using namespace std;



int main() {

    int t;

    cin >> t;

    while (t--) {

        int a, b;

        cin >> a >> b;

        

        // Valuation 1: 10 * a

        // Valuation 2: 5 * b

        // Comparison: 10 * a vs 5 * b

        // Simplified: 2 * a vs b

        

        if (2 * a > b) {

            cout << "FIRST" << endl;

        } else if (2 * a < b) {

            cout << "SECOND" << endl;

        } else {

            cout << "ANY" << endl;

        }

    }

    return 0;

}