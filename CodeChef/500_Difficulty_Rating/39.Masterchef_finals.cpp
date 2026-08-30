/*
 * CodeChef TOP10 - Masterchef finals [255]
 *
 * @platform   CodeChef
 * @id         TOP10
 * @title      Masterchef finals
 * @difficulty 255
 * @topics     Conditional Statements
 * @pattern    Threshold Comparison
 * @url        https://www.codechef.com/problems/TOP10
 * @solved     2026-06-05
 *
 * Approach
 * A rank qualifies for the finals exactly when it is within the top ten.
 *
 * Complexity
 * O(1) time and O(1) space per test case.
 *
 * Notes
 * - Rank 10 qualifies and must be included by using <=.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	

	for(int i = 1; i <= T; i++){

	    cin >> X;

	    if(X <= 10){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}



}
