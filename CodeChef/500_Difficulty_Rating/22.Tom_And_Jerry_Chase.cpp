/*
 * CodeChef JERRYCHASE - Tom And Jerry Chase [298]
 *
 * @platform   CodeChef
 * @id         JERRYCHASE
 * @title      Tom And Jerry Chase
 * @difficulty 298
 * @topics     Conditional Statements, Implementation, Basic Programming
 * @pattern    Single strict inequality per query
 * @url        https://www.codechef.com/problems/JERRYCHASE
 * @solved     2026-06-10
 *
 * Problem
 * Tom is chasing Jerry.
 *
 * Approach
 * There is no algorithm to design here -- the whole problem collapses to one comparison.
 * The only decision that carries any subtlety is the boundary: escape requires Y to *beat*
 * X, not merely match it.
 *
 * Complexity
 * Time: O(T) -- constant work (one read pair + one compare) per test case.
 * Space: O(1) -- only the scalars T, X, Y are held; nothing is stored across iterations,
 * so memory does not grow with T.
 *
 * Notes
 * - Y == X (a tie): must be "NO".
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

	    if(Y>X){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

	return 0;

}
