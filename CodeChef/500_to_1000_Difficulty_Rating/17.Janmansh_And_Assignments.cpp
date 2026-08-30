/*
 * CodeChef JASSIGNMENTS - Janmansh and Assignments [513]
 *
 * @platform   CodeChef
 * @id         JASSIGNMENTS
 * @title      Janmansh and Assignments
 * @difficulty 513
 * @topics     Implementation, Conditionals, Basic Programming
 * @pattern    Threshold Comparison (X vs 7)
 * @url        https://www.codechef.com/problems/JASSIGNMENTS
 * @solved     2026-06-08
 *
 * Problem
 * Janmansh must finish X assignments.
 *
 * Approach
 * "One assignment per day, seven days" collapses to a single capacity number: 7. The
 * maximum work achievable in a week is exactly 7 assignments, so the whole question
 * reduces to "is X <= 7?".
 *
 * Complexity
 * Time: O(T) -- one read and one comparison per test case, nothing nested.
 * Space: O(1) -- only the scalars T, X, i are kept; no arrays or buffers.
 *
 * Notes
 * - X == 7 exactly: the strict `>` keeps this in the "Yes" branch (a full week is enough),
 *   which is the correct and easiest case to get wrong.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T,X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    if(X > 7){

	        cout << "No" << endl;

	    }

	    else{

	        cout << "Yes" << endl;

	    }

	}



}
