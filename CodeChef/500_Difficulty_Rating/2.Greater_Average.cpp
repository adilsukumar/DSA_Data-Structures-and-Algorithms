/*
 * CodeChef AVGPROBLEM - Greater Average [500]
 *
 * @platform   CodeChef
 * @id         AVGPROBLEM
 * @title      Greater Average
 * @difficulty 500
 * @topics     Basic Math, Implementation
 * @pattern    Avoid-division integer comparison
 * @url        https://www.codechef.com/problems/AVGPROBLEM
 * @solved     2026-06-07
 *
 * Problem
 * For each of T test cases you are given three integers A, B, C.
 *
 * Approach
 * The naive test is: (A + B) / 2 > C. But dividing by 2 in integer arithmetic truncates,
 * so a genuine average of 3.5 would collapse to 3 and could flip the answer.
 *
 * Complexity
 * Time: O(T) — a fixed amount of work (two reads-into-compare) per case.
 * Space: O(1) — four scalar ints reused across all iterations; nothing scales with T.
 *
 * Notes
 * - Equality must print NO because the required comparison is strictly greater.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, A, B, C;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> A;

	    cin >> B;

	    cin >> C;

	    if ((A+B) > 2*C){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

    return 0;

}
