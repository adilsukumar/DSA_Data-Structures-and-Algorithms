/*
 * CodeChef TIMELY - Reach on Time [279]
 *
 * @platform   CodeChef
 * @id         TIMELY
 * @title      Reach on Time
 * @difficulty 279
 * @topics     Basic Programming Concepts
 * @pattern    Threshold Comparison
 * @url        https://www.codechef.com/problems/TIMELY
 * @solved     2026-06-07
 *
 * Approach
 * Reaching on time is possible exactly when X is at least 30.
 *
 * Complexity
 * O(1) time and O(1) space per test case.
 *
 * Notes
 * - X == 30 is successful, so the comparison must be >= rather than >.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	for (int i = 0; i < T; i++){

	    cin >> X;

	    if (X >= 30){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

    return 0;

}
