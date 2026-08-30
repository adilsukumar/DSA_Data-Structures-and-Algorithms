/*
 * CodeChef BESTOFTWO - Best Of Two [284]
 *
 * @platform   CodeChef
 * @id         BESTOFTWO
 * @title      Best Of Two
 * @difficulty 284
 * @topics     Implementation, Basics
 * @pattern    Max Of Two Values
 * @url        https://www.codechef.com/problems/BESTOFTWO
 * @solved     2026-06-07
 *
 * Problem
 * Chef has two scores, X and Y, for a subject: one from an assignment and one
 *
 * Approach
 * "Best of two" is literally the maximum of the pair. There is no state to carry across
 * test cases, no combination of the values -- each answer depends only on its own X and Y.
 *
 * Complexity
 * Time: O(T) -- a fixed amount of work (one compare, one print) per case.
 * Space: O(1) -- three ints reused every iteration; nothing scales with T.
 *
 * Notes
 * - X == Y (a tie): the else-branch prints Y, which equals X.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	for (int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    if(X>Y){

	        cout << X << endl;

	    }

	    else{

	        cout << Y << endl;

	    }

	}

    return 0;

}
