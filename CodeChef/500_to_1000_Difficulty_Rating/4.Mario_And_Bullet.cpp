/*
 * CodeChef BULLET - Mario And Bullet [650]
 *
 * @platform   CodeChef
 * @id         BULLET
 * @title      Mario And Bullet
 * @difficulty 650
 * @topics     Math, Implementation
 * @pattern    Time = distance / speed
 * @url        https://www.codechef.com/problems/BULLET
 * @solved     2026-07-27
 *
 * Problem
 * Mario fires a bullet toward an enemy.
 *
 * Approach
 * Compute time as distance / speed, compare it with deadline Z, and return the remaining
 * time or 0 if the bullet arrives too late.
 *
 * Complexity
 * Time: O(T) -- constant work (one division, one compare) per test case.
 * Space: O(1) -- only a handful of scalar ints, nothing scales with input.
 *
 * Notes
 * - Bullet exactly on time (seconds_taken == Z): prints 0, which is correct - there is
 *   zero time to spare, handled by the else branch (Z - Z = 0).
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y, Z;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X >> Y >> Z;

	    int seconds_taken = Y/X;

	    if(seconds_taken > Z){

	        cout << 0 << endl;

	    }

	    else{

	        cout << Z - seconds_taken << endl;

	    }

	}

	return 0;

}
