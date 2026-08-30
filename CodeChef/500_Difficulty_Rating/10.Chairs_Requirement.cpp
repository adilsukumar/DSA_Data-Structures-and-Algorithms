/*
 * CodeChef CHAIRS_ - Chairs Requirement [305]
 *
 * @platform   CodeChef
 * @id         CHAIRS_
 * @title      Chairs Requirement
 * @difficulty 305
 * @topics     Basic Math, Implementation
 * @pattern    Clamped Difference max(X-Y, 0)
 * @url        https://www.codechef.com/problems/CHAIRS_
 * @solved     2026-06-12
 *
 * Problem
 * For each of T independent test cases you are given two integers on a line: X = the
 * number of chairs you currently have, and Y = the number of chairs actually needed.
 *
 * Approach
 * The whole task is a single expression: max(X - Y, 0). We never care by how much we fall
 * short, only whether a surplus exists and how big it is.
 *
 * Complexity
 * Time: O(T) overall -- constant work (one compare, one subtraction, one print) per test
 * case, so it scales linearly in the number of cases.
 * Space: O(1) -- only the scalars T, X, Y are kept; nothing is stored per case.
 *
 * Notes
 * - X == Y: falls into the `>=` branch and prints X-Y = 0 (correct, no surplus).
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    if(X>=Y){

	        cout << X-Y << endl;

	    }

	    else{

	        cout << 0 << endl;

	    }

	}

    return 0;

}
