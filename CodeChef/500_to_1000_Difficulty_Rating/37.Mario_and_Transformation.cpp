/*
 * =============================================================================
 * CodeChef TRANSFORM - Mario and Transformation (Difficulty 649)
 * =============================================================================
 * @platform   CodeChef
 * @id         TRANSFORM
 * @title      Mario and Transformation
 * @difficulty 649
 * @topics     Observation
 * @pattern    Cycle by Modulo
 * @url        https://www.codechef.com/problems/TRANSFORM
 * @solved     2026-07-27
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * Mario's form repeats every three transformations, so only X mod 3 matters.
 *
 * WALKTHROUGH
 * Compute X % 3: remainder 0 maps to NORMAL, 1 to HUGE, and 2 to SMALL.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(1) time and O(1) space per test case.
 *
 * EDGE CASES
 * The mapping is cyclic, so very large X needs no simulation.
 * =============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    if(X%3 == 1){

	        cout << "HUGE" << endl;

	    }

	    else if(X%3 == 0){

	        cout << "NORMAL" << endl;

	    }

	    else{

	        cout << "SMALL" << endl;

	    }

	}

	return 0;

}
