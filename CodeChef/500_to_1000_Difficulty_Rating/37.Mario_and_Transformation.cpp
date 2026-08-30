/*
 * CodeChef TRANSFORM - Mario and Transformation [649]
 *
 * @platform   CodeChef
 * @id         TRANSFORM
 * @title      Mario and Transformation
 * @difficulty 649
 * @topics     Observation
 * @pattern    Cycle by Modulo
 * @url        https://www.codechef.com/problems/TRANSFORM
 * @solved     2026-07-27
 *
 * Approach
 * Mario's form repeats every three transformations, so only X mod 3 matters.
 *
 * Complexity
 * O(1) time and O(1) space per test case.
 *
 * Notes
 * - The mapping is cyclic, so very large X needs no simulation.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    if(X%3 == 1){

	        cout << "HUGE" << endl;

	    }

	    else if(X%3 == 0){

	        cout << "NORMAL" << endl;

	    }

	    else{

	        cout << "SMALL" << endl;

	    }

	}

	return 0;

}
