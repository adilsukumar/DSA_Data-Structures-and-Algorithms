/*
 * =============================================================================
 * CodeChef REACHTARGET - Reach the Target (Difficulty 281)
 * =============================================================================
 * @platform   CodeChef
 * @id         REACHTARGET
 * @title      Reach the Target
 * @difficulty 281
 * @topics     Mathematics, Basic Math
 * @pattern    Direct Difference
 * @url        https://www.codechef.com/problems/REACHTARGET
 * @solved     2026-06-07
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * The target is Y units behind X, so the required movement is simply X - Y.
 *
 * WALKTHROUGH
 * For every test case, read X and Y and print X - Y. No search or simulation is needed because subtraction gives the distance directly.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(1) time and O(1) extra space per test case.
 *
 * EDGE CASES
 * The constraints guarantee the subtraction represents the required non-negative distance.
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

	    cout << (X) - Y << endl;

	    }



}
