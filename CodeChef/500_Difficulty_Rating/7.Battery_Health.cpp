/*
 * CodeChef BTRYHLTH - Battery Health [296]
 *
 * @platform   CodeChef
 * @id         BTRYHLTH
 * @title      Battery Health
 * @difficulty 296
 * @topics     Conditional Statements, Implementation
 * @pattern    Single Threshold Comparison
 * @url        https://www.codechef.com/problems/BTRYHLTH
 * @solved     2026-06-07
 *
 * Problem
 * A phone battery is considered "healthy" if its health is at least 80%.
 *
 * Approach
 * There is nothing to compute or search here -- the answer is a direct function of a
 * single number. The only thing that can trip you up is the boundary: "at least 80" means
 * 80 itself counts, so the correct test is ">= 80", NOT "> 80".
 *
 * Complexity
 * Time: O(T) -- one read and one constant-time comparison per test case.
 * Space: O(1) -- only the scalars T, X, i; nothing scales with input.
 *
 * Notes
 * - Exactly 80: handled correctly because the comparison is inclusive (`>=`).
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

    int T, X;

    cin >> T;

    

    for (int i = 0; i < T; i++){

        cin >> X;

        if(X >= 80){

            cout << "YES" << endl;

        }

        else{

            cout << "NO" << endl;

        }

    }

    return 0;

}
