/*
 * CodeChef SALESEASON - Sale Season [541]
 *
 * @platform   CodeChef
 * @id         SALESEASON
 * @title      Sale Season
 * @difficulty 541
 * @topics     Basic Programming Concepts
 * @pattern    Piecewise Discount
 * @url        https://www.codechef.com/problems/SALESEASON
 * @solved     2026-06-10
 *
 * Approach
 * The discount is determined solely by the price interval containing X.
 *
 * Complexity
 * O(1) time and O(1) space per test case.
 *
 * Notes
 * - Boundary values 100, 1000, and 5000 must remain in the bracket specified by the
 *   statement.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    if(X <= 100){

	        cout << X << endl;

	    }

	    else if(X > 100 && X <= 1000){

	        cout << X-25 << endl;

	    }

	    else if(X > 1000 && X <= 5000){

	        cout << X-100 << endl;

	    }

	    else{

	        cout << X-500 << endl;

	    }

	}

    return 0;

}
