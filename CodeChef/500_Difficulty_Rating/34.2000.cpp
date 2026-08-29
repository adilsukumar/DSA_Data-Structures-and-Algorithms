/*
 * =============================================================================
 * CodeChef RIP2000 - 2000 (Difficulty 284)
 * =============================================================================
 * @platform   CodeChef
 * @id         RIP2000
 * @title      2000
 * @difficulty 284
 * @topics     Basic Math
 * @pattern    Direct Multiplication
 * @url        https://www.codechef.com/problems/RIP2000
 * @solved     2026-06-07
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * Each unit contributes four items, so N units contribute 4 * N.
 *
 * WALKTHROUGH
 * Read N once, multiply it by 4, and print the product.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(1) time and O(1) space.
 *
 * EDGE CASES
 * Use a type large enough for 4 * N under the stated constraints.
 * =============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int N;

	cin >> N;

	

	cout << N*4 << endl;

	return 0;

}
