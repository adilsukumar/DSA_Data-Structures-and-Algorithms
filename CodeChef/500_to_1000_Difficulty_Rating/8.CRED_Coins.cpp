/*
 * CodeChef CREDCOINS - CRED Coins [539]
 *
 * @platform   CodeChef
 * @id         CREDCOINS
 * @title      CRED Coins
 * @difficulty 539
 * @topics     Math, Basic Programming, Implementation
 * @pattern    Integer Division (floor total/100)
 * @url        https://www.codechef.com/problems/CREDCOINS
 * @solved     2026-06-10
 *
 * Problem
 * For every 100 rupees a user pays, CRED rewards exactly 1 CRED coin (fractional coins are
 * not awarded).
 *
 * Approach
 * Coins earned = floor(amount / 100), because you only get a coin once a *full* block of
 * 100 rupees is spent. Integer division in C++ already truncates toward zero, and since
 * amount = X*Y is non-negative here, truncation IS the floor we want.
 *
 * Complexity
 * Time: O(T) — a constant amount of work (one multiply, one divide, one compare) per test
 * case.
 * Space: O(1) — only the scalars T, X, Y are held; no arrays.
 *
 * Notes
 * - A bill below 100 earns zero coins; exactly 100 earns one.
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

	    

	    if(X*Y >= 100){

	        cout << (X*Y)/100 << endl;

	    }

	    else{

	        cout << 0 << endl;

	    }

	}

    return 0;   

}
