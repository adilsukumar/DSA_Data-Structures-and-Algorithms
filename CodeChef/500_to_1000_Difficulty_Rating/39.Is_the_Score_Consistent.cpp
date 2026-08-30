/*
 * CodeChef TRUESCORE - Is the Score Consistent [572]
 *
 * @platform   CodeChef
 * @id         TRUESCORE
 * @title      Is the Score Consistent
 * @difficulty 572
 * @topics     Conditional Statements
 * @pattern    Coordinate-Wise Monotonicity
 * @url        https://www.codechef.com/problems/TRUESCORE
 * @solved     2026-06-19
 *
 * Approach
 * A score update is consistent only if neither participant's score decreases.
 *
 * Complexity
 * O(1) time and O(1) space per test case.
 *
 * Notes
 * - One non-decreasing score cannot compensate for the other decreasing; the conditions
 *   must be joined with AND.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, A, B, C, D;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> A >> B;

	    cin >> C >> D;

	    if((A<=C && B<=D)){

	        cout << "POSSIBLE" << endl;

	    }

	    else{

	        cout << "IMPOSSIBLE" << endl;

	    }

	}

	return 0;

}
