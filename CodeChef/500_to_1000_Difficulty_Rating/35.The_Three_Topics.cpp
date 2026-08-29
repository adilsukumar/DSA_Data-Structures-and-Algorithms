/*
 * =============================================================================
 * CodeChef THREETOPICS - The Three Topics (Difficulty 573)
 * =============================================================================
 * @platform   CodeChef
 * @id         THREETOPICS
 * @title      The Three Topics
 * @difficulty 573
 * @topics     Conditional Statements
 * @pattern    Membership Among Three
 * @url        https://www.codechef.com/problems/THREETOPICS
 * @solved     2026-06-20
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * Chef knows the requested topic when X equals any one of A, B, or C.
 *
 * WALKTHROUGH
 * Evaluate the three equality checks joined by logical OR, then print Yes or No.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(1) time and O(1) space.
 *
 * EDGE CASES
 * The code uses bitwise | for the final Boolean comparison. It works for bool values but logical || is clearer and short-circuits.
 * =============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int A,B,C,X;

	

    cin >> A >> B >> C >> X;

    if(X == A || X == B | X == C){

        cout << "Yes" << endl;

    }

    else{

        cout << "No" << endl;

	}

}
