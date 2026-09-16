/*
 * CodeChef SUMM - Sum it [308]
 *
 * @platform   CodeChef
 * @id         SUMM
 * @title      Sum it
 * @difficulty 308
 * @topics     Basic Programming Concepts
 * @pattern    Condition Check
 * @url        https://www.codechef.com/problems/SUMM
 * @solved     2026-09-16
 *
 * Problem
 * Accepted solution for Sum it.
 *
 * Approach
 * The solution reads a number of test cases and for each, reads three integers A,
 * B, and C. It then checks if C is equal to the sum of A and B, and prints "YES"
 * or "NO" accordingly. This is a straightforward conditional check without any
 * complex algorithmic patterns.
 *
 * Complexity
 * Time: O(T) Space: O(1)
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

    int T, A, B, C;

    cin >> T;

    

    for(int i = 0; i < T; i++){

        cin >> A >> B >> C;

        if(C == A+B){

            cout << "YES\n";

        }

        else{

            cout << "NO\n";

        }

    }

    return 0;

}
