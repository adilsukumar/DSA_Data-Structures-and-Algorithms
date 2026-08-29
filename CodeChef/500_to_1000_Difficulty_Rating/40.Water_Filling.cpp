/*
 * =============================================================================
 * CodeChef WATERFILLING - Water Filling (Difficulty 541)
 * =============================================================================
 * @platform   CodeChef
 * @id         WATERFILLING
 * @title      Water Filling
 * @difficulty 541
 * @topics     admin, start92
 * @pattern    Count Empty Bottles
 * @url        https://www.codechef.com/problems/WATERFILLING
 * @solved     2026-06-10
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * Water must be filled when at least two of the three bottles are empty (represented by zero).
 *
 * WALKTHROUGH
 * The code checks each possible pair of zeros and prints the filling message if any pair matches; otherwise it prints Not now. An equivalent shorter test is B1 + B2 + B3 <= 1.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(1) time and O(1) space per test case.
 *
 * EDGE CASES
 * All three empty bottles also satisfy the first pair check, as required.
 * =============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, B1, B2, B3;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> B1;

	    cin >> B2;

	    cin >> B3;

	    

	    if(B1 == 0 && B2 == 0){

	        cout << "Water filling time" << endl;

	    }

	    else if(B1 == 0 && B3 == 0){

	        cout << "Water filling time" << endl;

	    }

	    else if(B2 == 0 && B3 == 0){

	        cout << "Water filling time" << endl;

	    }

	    else{

	        cout << "Not now" << endl;

	    }

	}

	return 0;

}
