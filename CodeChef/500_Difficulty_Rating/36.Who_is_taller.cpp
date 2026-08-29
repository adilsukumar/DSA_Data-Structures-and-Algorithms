/*
 * =============================================================================
 * CodeChef TALLER - Who is taller! (Difficulty 281)
 * =============================================================================
 * @platform   CodeChef
 * @id         TALLER
 * @title      Who is taller!
 * @difficulty 281
 * @topics     lavish_adm, math, start36
 * @pattern    Two-Way Comparison
 * @url        https://www.codechef.com/problems/TALLER
 * @solved     2026-06-07
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * The taller person is determined by comparing heights X and Y.
 *
 * WALKTHROUGH
 * Print A when X > Y; otherwise print B.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(1) time and O(1) space per test case.
 *
 * EDGE CASES
 * The problem guarantees distinct heights; otherwise the else branch would classify a tie as B.
 * =============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    if(X>Y){

	        cout << "A" << endl;

	    }

	    else{

	        cout << "B" << endl;

	    }

	}

	return 0;

}
