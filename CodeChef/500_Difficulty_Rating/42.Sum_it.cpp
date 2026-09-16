/*
 * CodeChef SUMM - Sum it [308]
 *
 * @platform   CodeChef
 * @id         SUMM
 * @title      Sum it
 * @difficulty 308
 * @topics     Basic Programming Concepts
 * @pattern    Direct Computation
 * @url        https://www.codechef.com/problems/SUMM
 * @solved     2026-09-16
 *
 * Problem
 * Accepted solution for Sum it.
 *
 * Approach
 * The solution iterates through T test cases. For each case, it reads integers A,
 * B, and C. It directly checks if C equals the sum of A and B, printing 'YES' if
 * true and 'NO' otherwise.
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
