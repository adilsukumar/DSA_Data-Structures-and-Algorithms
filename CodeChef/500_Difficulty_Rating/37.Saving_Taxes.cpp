/*
 * =============================================================================
 * CodeChef TAXSAVING - Saving Taxes (Difficulty 252)
 * =============================================================================
 * @platform   CodeChef
 * @id         TAXSAVING
 * @title      Saving Taxes
 * @difficulty 252
 * @topics     Basic Math
 * @pattern    Direct Subtraction
 * @url        https://www.codechef.com/problems/TAXSAVING
 * @solved     2026-06-05
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * The maximum amount that can be saved is the difference between income X and the tax-free threshold Y.
 *
 * WALKTHROUGH
 * Read X and Y and print X - Y for each test case.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(1) time and O(1) space per test case.
 *
 * EDGE CASES
 * The extra blank line printed before all answers is unnecessary and may be removed for exact output formatting.
 * =============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	cout << endl;

	

	for (int i = 1; i <= T; i++){

	    cin >> X;

	    cin >> Y;

	    cout << X-Y << endl;

	}

}
