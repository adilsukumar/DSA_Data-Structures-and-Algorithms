/*
 * CodeChef SUBSCRIBE_ - Subscriptions [504]
 *
 * @platform   CodeChef
 * @id         SUBSCRIBE_
 * @title      Subscriptions
 * @difficulty 504
 * @topics     Basic Math, Implementation
 * @pattern    Ceiling Division
 * @url        https://www.codechef.com/problems/SUBSCRIBE_
 * @solved     2026-06-08
 *
 * Approach
 * One subscription covers six people, so the number needed is ceil(N/6), each costing X.
 *
 * Complexity
 * O(1) time and O(1) space per test case.
 *
 * Notes
 * - N below six still requires one complete subscription.
 */

#include <bits/stdc++.h>

#include <cmath>

using namespace std;



int main() {

	// your code goes here

	int T, N, X;

	cin >> T;

	for (int i = 0; i < T; i++){

	    cin >> N;

	    cin >> X;

	    if (N<6){

	        cout << X << endl;

	    }

	    else if (N%6 == 0){

	        cout << X * (N/6) << endl;

	    }

	    else{

	        cout << X * ceil(double(N)/6) << endl;

	    }

	}

}
