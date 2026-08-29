/*
 * =============================================================================
 * CodeChef SALESEASON - Sale Season (Difficulty 541)
 * =============================================================================
 * @platform   CodeChef
 * @id         SALESEASON
 * @title      Sale Season
 * @difficulty 541
 * @topics     Basic Programming Concepts
 * @pattern    Piecewise Discount
 * @url        https://www.codechef.com/problems/SALESEASON
 * @solved     2026-06-10
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * The discount is determined solely by the price interval containing X.
 *
 * WALKTHROUGH
 * Check the ranges in increasing order: no discount through 100, then subtract 25, 100, or 500 for the successive brackets.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(1) time and O(1) space per test case.
 *
 * EDGE CASES
 * Boundary values 100, 1000, and 5000 must remain in the bracket specified by the statement.
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

	    if(X <= 100){

	        cout << X << endl;

	    }

	    else if(X > 100 && X <= 1000){

	        cout << X-25 << endl;

	    }

	    else if(X > 1000 && X <= 5000){

	        cout << X-100 << endl;

	    }

	    else{

	        cout << X-500 << endl;

	    }

	}

    return 0;

}
