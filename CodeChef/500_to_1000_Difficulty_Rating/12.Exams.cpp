/*
 * CodeChef EXAMCHEF - Exams [519]
 *
 * @platform   CodeChef
 * @id         EXAMCHEF
 * @title      Exams
 * @difficulty 519
 * @topics     Math, Implementation
 * @pattern    Half-of-total threshold check
 * @url        https://www.codechef.com/problems/EXAMCHEF
 * @solved     2026-06-09
 *
 * Problem
 * For each test case you are given three integers X, Y, Z.
 *
 * Approach
 * "More than half of the total" is the whole problem. Total is X*Y, so the bar to clear is
 * (X*Y)/2, and the single test Z > bar decides everything.
 *
 * Complexity
 * Time: O(T).
 * Space: O(1).
 *
 * Notes
 * - Exactly half (Z == X*Y/2): prints NO.
 * - Use long long if N * X can exceed int.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y, Z;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    cin >> Z;

	    if(X*Y/2 < Z){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

	return 0;



}
