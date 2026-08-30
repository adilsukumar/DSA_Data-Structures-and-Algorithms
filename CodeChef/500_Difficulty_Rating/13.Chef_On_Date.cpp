/*
 * CodeChef CHEFONDATE - Chef On Date [294]
 *
 * @platform   CodeChef
 * @id         CHEFONDATE
 * @title      Chef On Date
 * @difficulty 294
 * @topics     Basic Programming, Conditionals, Implementation
 * @pattern    Direct Conditional Comparison
 * @url        https://www.codechef.com/problems/CHEFONDATE
 * @solved     2026-06-07
 *
 * Problem
 * Chef wants to go on a date.
 *
 * Approach
 * This is not an algorithm problem at all -- it is a single yes/no decision per test case.
 * The whole task reduces to one comparison, X >= Y.
 *
 * Complexity
 * Time: O(T) -- one read plus one comparison per test case, and nothing inside the loop
 * depends on the size of the values.
 * Space: O(1) -- three int variables reused across all iterations; no arrays or containers
 * are allocated.
 *
 * Notes
 * - X == Y (exactly enough): handled correctly by >=, prints "YES".
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

    int T, X, Y;

    cin >> T;

    

    for (int i = 0; i < T; i++) {

        cin >> X;

        cin >> Y;

        if (X >= Y){

            cout << "YES" << endl;

        }

        else{

            cout << "NO" << endl;

        }

    }

}
