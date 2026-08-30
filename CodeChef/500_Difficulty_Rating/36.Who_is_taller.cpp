/*
 * CodeChef TALLER - Who is taller! [281]
 *
 * @platform   CodeChef
 * @id         TALLER
 * @title      Who is taller!
 * @difficulty 281
 * @topics     lavish_adm, math, start36
 * @pattern    Two-Way Comparison
 * @url        https://www.codechef.com/problems/TALLER
 * @solved     2026-06-07
 *
 * Approach
 * The taller person is determined by comparing heights X and Y.
 *
 * Complexity
 * O(1) time and O(1) space per test case.
 *
 * Notes
 * - The problem guarantees distinct heights; otherwise the else branch would classify a
 *   tie as B.
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

	    if(X>Y){

	        cout << "A" << endl;

	    }

	    else{

	        cout << "B" << endl;

	    }

	}

	return 0;

}
