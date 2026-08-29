/*
 * =============================================================================
 * CodeChef TRAVELFAST - Car or Bike (Difficulty 571)
 * =============================================================================
 * @platform   CodeChef
 * @id         TRAVELFAST
 * @title      Car or Bike
 * @difficulty 571
 * @topics     Basic Math
 * @pattern    Compare Travel Times
 * @url        https://www.codechef.com/problems/TRAVELFAST
 * @solved     2026-06-18
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * Choose the vehicle with the smaller travel time; equal times mean either is equivalent.
 *
 * WALKTHROUGH
 * Compare X and Y and print CAR, BIKE, or SAME according to which time is lower or whether they match.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(1) time and O(1) space per test case.
 *
 * EDGE CASES
 * Keep the equality branch separate so ties are not assigned to either vehicle.
 * =============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T,X,Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X >> Y;

	    if(X>Y){

	        cout << "CAR" << endl;

	    }

	    else if(Y>X){

	        cout << "BIKE" << endl;

	    }

	    else{

	        cout << "SAME" << endl;

	    }

	}

	return 0;

}
