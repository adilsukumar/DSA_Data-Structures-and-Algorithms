/*
 * =============================================================================
 * CodeChef SUGARCANE - Sugarcane Juice Business (Difficulty 563)
 * =============================================================================
 * @platform   CodeChef
 * @id         SUGARCANE
 * @title      Sugarcane Juice Business
 * @difficulty 563
 * @topics     Basic Math
 * @pattern    Unit Profit
 * @url        https://www.codechef.com/problems/SUGARCANE
 * @solved     2026-06-16
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * The known net profit per glass is 15, so selling N glasses yields 15*N.
 *
 * WALKTHROUGH
 * Read N and print 15 multiplied by N for each test case.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(1) time and O(1) space per test case.
 *
 * EDGE CASES
 * The arithmetic already incorporates all stated costs; do not subtract them a second time.
 * =============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N;

	    cout << 15 * N << endl;

	}

	return 0;



}
