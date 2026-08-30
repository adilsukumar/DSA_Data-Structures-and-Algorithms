/*
 * CodeChef TAXSAVING - Saving Taxes [252]
 *
 * @platform   CodeChef
 * @id         TAXSAVING
 * @title      Saving Taxes
 * @difficulty 252
 * @topics     Basic Math
 * @pattern    Direct Subtraction
 * @url        https://www.codechef.com/problems/TAXSAVING
 * @solved     2026-06-05
 *
 * Approach
 * The maximum amount that can be saved is the difference between income X and the tax-free
 * threshold Y.
 *
 * Complexity
 * O(1) time and O(1) space per test case.
 *
 * Notes
 * - The extra blank line printed before all answers is unnecessary and may be removed for
 *   exact output formatting.
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
