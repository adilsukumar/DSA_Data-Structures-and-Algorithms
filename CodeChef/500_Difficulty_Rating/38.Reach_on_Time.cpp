/*
 * =============================================================================
 * CodeChef TIMELY - Reach on Time (Difficulty 279)
 * =============================================================================
 * @platform   CodeChef
 * @id         TIMELY
 * @title      Reach on Time
 * @difficulty 279
 * @topics     Basic Programming Concepts
 * @pattern    Threshold Comparison
 * @url        https://www.codechef.com/problems/TIMELY
 * @solved     2026-06-07
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * Reaching on time is possible exactly when X is at least 30.
 *
 * WALKTHROUGH
 * Compare X with 30 and print YES when X >= 30, otherwise NO.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(1) time and O(1) space per test case.
 *
 * EDGE CASES
 * X == 30 is successful, so the comparison must be >= rather than >.
 * =============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	for (int i = 0; i < T; i++){

	    cin >> X;

	    if (X >= 30){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

    return 0;

}
