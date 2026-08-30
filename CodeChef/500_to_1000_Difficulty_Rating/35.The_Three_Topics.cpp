/*
 * CodeChef THREETOPICS - The Three Topics [573]
 *
 * @platform   CodeChef
 * @id         THREETOPICS
 * @title      The Three Topics
 * @difficulty 573
 * @topics     Conditional Statements
 * @pattern    Membership Among Three
 * @url        https://www.codechef.com/problems/THREETOPICS
 * @solved     2026-06-20
 *
 * Approach
 * Chef knows the requested topic when X equals any one of A, B, or C.
 *
 * Complexity
 * O(1) time and O(1) space.
 *
 * Notes
 * - The code uses bitwise | for the final Boolean comparison.
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
