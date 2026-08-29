/*
 * =============================================================================
 * CodeChef SEATNUMBER - Bus  Seat Numbering (Difficulty 613)
 * =============================================================================
 * @platform   CodeChef
 * @id         SEATNUMBER
 * @title      Bus  Seat Numbering
 * @difficulty 613
 * @topics     Conditional Statements, Implementation
 * @pattern    Range Classification
 * @url        https://www.codechef.com/problems/SEATNUMBER
 * @solved     2026-07-19
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * A seat number identifies one of four sections through fixed numerical ranges.
 *
 * WALKTHROUGH
 * Check the ranges from lowest to highest and print the matching Lower/Upper and Double/Single label.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(1) time and O(1) space per test case.
 *
 * EDGE CASES
 * The condition N >= 10 in the second branch overlaps N == 10, but the first branch already consumes that value; non-overlapping bounds would be clearer.
 * =============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes 

	int N, T;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N;

	    if(N <= 10){

	        cout << "Lower Double" << endl;

	    }

	    else if(N >= 10 && N <= 15){

	        cout << "Lower Single" << endl;

	    }

	    else if(N >= 16 && N <= 25){

	        cout << "Upper Double" << endl;

	    }

	    else{

	        cout << "Upper Single" << endl;

	    }

	}

    return 0;

}
