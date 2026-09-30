/*
 * CodeChef FSQRT - Finding Square Roots [668]
 *
 * @platform   CodeChef
 * @id         FSQRT
 * @title      Finding Square Roots
 * @difficulty 668
 * @topics     Inbuilt functions
 * @pattern    Direct Calculation
 * @url        https://www.codechef.com/problems/FSQRT
 * @solved     2026-09-30
 *
 * Problem
 * Accepted solution for Finding Square Roots.
 *
 * Approach
 * The solution simply reads the integer N and computes the square root using the
 * built-in `sqrt` function from the standard library. The result is then rounded
 * to the nearest integer using the `round` function and printed. It does not
 * implement a search or iterative algorithm.
 *
 * Complexity
 * Time: O(T) Space: O(1)
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

    int T, N;

    cin >> T;

    for(int i = 0; i < T; i++){

        cin >> N;

        cout << round(sqrt(N)) << endl;

    }

    return 0;

}
