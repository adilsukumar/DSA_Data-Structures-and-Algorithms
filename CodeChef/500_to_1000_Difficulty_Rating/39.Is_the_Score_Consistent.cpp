/*
 * =============================================================================
 * CodeChef TRUESCORE - Is the Score Consistent (Difficulty 572)
 * =============================================================================
 * @platform   CodeChef
 * @id         TRUESCORE
 * @title      Is the Score Consistent
 * @difficulty 572
 * @topics     Conditional Statements
 * @pattern    Coordinate-Wise Monotonicity
 * @url        https://www.codechef.com/problems/TRUESCORE
 * @solved     2026-06-19
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * A score update is consistent only if neither participant's score decreases.
 *
 * WALKTHROUGH
 * For old scores A,B and new scores C,D, require A <= C and B <= D; print POSSIBLE only when both hold.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(1) time and O(1) space per test case.
 *
 * EDGE CASES
 * One non-decreasing score cannot compensate for the other decreasing; the conditions must be joined with AND.
 * =============================================================================
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
