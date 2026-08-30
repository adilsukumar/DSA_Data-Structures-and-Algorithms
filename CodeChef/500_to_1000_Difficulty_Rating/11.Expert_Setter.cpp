/*
 * CodeChef EXPERT - Expert Setter [561]
 *
 * @platform   CodeChef
 * @id         EXPERT
 * @title      Expert Setter
 * @difficulty 561
 * @topics     Basic Math, Implementation
 * @pattern    Constant-time inequality check
 * @url        https://www.codechef.com/problems/EXPERT
 * @solved     2026-06-15
 *
 * Problem
 * For each of T independent test cases you are given two integers X and Y.
 *
 * Approach
 * The whole problem is one comparison. The only genuinely useful trick is to test 2*Y >= X
 * instead of Y >= X/2.
 *
 * Complexity
 * Time: O(T) overall, O(1) per test -- one multiply and one compare each.
 * Space: O(1) -- three scalar ints reused across every iteration; nothing is accumulated.
 *
 * Notes
 * - Exact half (2*Y == X): the `>=` includes equality, so a precise half counts as YES.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	for (int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    

	    if(Y*2 >= X){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}



}
