/*
 * CodeChef CANDIVIDE - Candy Division [289]
 *
 * @platform   CodeChef
 * @id         CANDIVIDE
 * @title      Candy Division
 * @difficulty 289
 * @topics     Conditional Statements, Basic Math
 * @pattern    Divisibility Check (N mod 3)
 * @url        https://www.codechef.com/problems/CANDIVIDE
 * @solved     2026-06-07
 *
 * Problem
 * Chef has N candies and wants to split them EQUALLY among his 3 friends, with no candy
 * left over and none broken.
 *
 * Approach
 * "Divide N into 3 equal whole parts" is exactly the definition of "N is divisible by 3".
 * There is no need to actually compute the shares or search anything -- a single remainder
 * test settles it.
 *
 * Complexity
 * Time: O(T) -- one read + one modulo + one print per test case; the work per case is
 * constant, so total is linear in the number of test cases.
 * Space: O(1) -- only the scalars T, N, i are stored; no arrays or buffers that grow with
 * the input.
 *
 * Notes
 * - N = 0: 0 % 3 == 0 -> YES.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N;

	cin >> T;

	

	for (int i = 0; i < T; i++){

	    cin >> N;

	    if (N%3 == 0){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}



}
