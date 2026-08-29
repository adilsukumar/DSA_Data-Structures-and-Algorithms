/*
 * =============================================================================
 * CodeChef SUBSCRIBE_ - Subscriptions (Difficulty 504)
 * =============================================================================
 * @platform   CodeChef
 * @id         SUBSCRIBE_
 * @title      Subscriptions
 * @difficulty 504
 * @topics     Basic Math, Implementation
 * @pattern    Ceiling Division
 * @url        https://www.codechef.com/problems/SUBSCRIBE_
 * @solved     2026-06-08
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * One subscription covers six people, so the number needed is ceil(N/6), each costing X.
 *
 * WALKTHROUGH
 * For multiples of six use N/6; otherwise round up and multiply by X. The formula (N + 5) / 6 performs the same ceiling division with integers.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(1) time and O(1) space per test case.
 *
 * EDGE CASES
 * N below six still requires one complete subscription.
 * =============================================================================
 */

#include <bits/stdc++.h>

#include <cmath>

using namespace std;



int main() {

	// your code goes here

	int T, N, X;

	cin >> T;

	for (int i = 0; i < T; i++){

	    cin >> N;

	    cin >> X;

	    if (N<6){

	        cout << X << endl;

	    }

	    else if (N%6 == 0){

	        cout << X * (N/6) << endl;

	    }

	    else{

	        cout << X * ceil(double(N)/6) << endl;

	    }

	}

}
