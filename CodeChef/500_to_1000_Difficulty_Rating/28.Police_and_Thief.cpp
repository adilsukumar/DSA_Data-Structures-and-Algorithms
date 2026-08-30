/*
 * CodeChef POLTHIEF - Police and Thief [639]
 *
 * @platform   CodeChef
 * @id         POLTHIEF
 * @title      Police and Thief
 * @difficulty 639
 * @topics     Basic Math, Implementation
 * @pattern    Absolute Difference |X - Y|
 * @url        https://www.codechef.com/problems/POLTHIEF
 * @solved     2026-07-19
 *
 * Problem
 * A police officer stands at position X and a thief at position Y on a line.
 *
 * Approach
 * Distance on a number line is direction-agnostic: whether the police is left or right of
 * the thief, the gap between them is the same magnitude. That gap is |X - Y|.
 *
 * Complexity
 * Time: O(T) -- constant work (one compare, one subtract, one print) per test case;
 * nothing is stored or revisited.
 * Space: O(1) -- three int scalars reused across all iterations; no arrays.
 *
 * Notes
 * - X == Y (same position): handled by the >= branch, prints 0.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X >> Y;

	    if(X >= Y){

	        cout << X-Y << endl;

	    }

	    else{

	        cout << Y-X << endl;

	    }

	}

	return 0;

}
