/*
 * CodeChef NIBBLE - Good Program [593]
 *
 * @platform   CodeChef
 * @id         NIBBLE
 * @title      Good Program
 * @difficulty 593
 * @topics     Divisibility, Integer Division, Implementation
 * @pattern    Modulo Divisibility Check
 * @url        https://www.codechef.com/problems/NIBBLE
 * @solved     2026-07-15
 *
 * Problem
 * You are given T independent test cases.
 *
 * Approach
 * "Divisible by 4" is exactly "the remainder when dividing by 4 is zero". The modulo
 * operator X % 4 computes that remainder directly, so a single comparison X % 4 == 0
 * settles each case.
 *
 * Complexity
 * Time: O(T) overall -- O(1) work (one modulo, one compare) per test case.
 * Space: O(1) -- only the scalars T, X, i are stored; nothing scales with T.
 *
 * Notes
 * - X = 0: 0 % 4 == 0 -> "Good".
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    if(X%4 == 0){

	        cout << "Good" << endl;

	    }

	    else{

	        cout << "Not Good" << endl;

	    }

	}

	return 0;

}
