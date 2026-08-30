/*
 * CodeChef REACHTARGET - Reach the Target [281]
 *
 * @platform   CodeChef
 * @id         REACHTARGET
 * @title      Reach the Target
 * @difficulty 281
 * @topics     Mathematics, Basic Math
 * @pattern    Direct Difference
 * @url        https://www.codechef.com/problems/REACHTARGET
 * @solved     2026-06-07
 *
 * Approach
 * The target is Y units behind X, so the required movement is simply X - Y.
 *
 * Complexity
 * O(1) time and O(1) extra space per test case.
 *
 * Notes
 * - The constraints guarantee the subtraction represents the required non-negative
 *   distance.
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

	    cout << (X) - Y << endl;

	    }



}
