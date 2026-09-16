/*
 * CodeChef SUBSCRIBE - Get Subscription [315]
 *
 * @platform   CodeChef
 * @id         SUBSCRIBE
 * @title      Get Subscription
 * @difficulty 315
 * @topics     Implementation
 * @pattern    Conditional Logic
 * @url        https://www.codechef.com/problems/SUBSCRIBE
 * @solved     2026-09-16
 *
 * Problem
 * Accepted solution for Get Subscription.
 *
 * Approach
 * The solution reads T test cases. For each test case, it reads a value X and
 * checks if it is greater than 30 using a simple conditional statement.
 *
 * Complexity
 * Time: O(T) Space: O(1)
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    if(X <= 30){

	        cout << "NO\n";

	    }

	    else{

	        cout << "YES\n";

	    }

	}

	return 0;

}
