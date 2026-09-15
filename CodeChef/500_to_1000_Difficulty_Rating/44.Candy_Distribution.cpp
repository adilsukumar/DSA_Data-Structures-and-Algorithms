/*
 * CodeChef CANDYDIST - Candy Distribution [668]
 *
 * @platform   CodeChef
 * @id         CANDYDIST
 * @title      Candy Distribution
 * @difficulty 668
 * @topics     Basic Programming Concepts, Basic Math
 * @pattern    Pending manual review
 * @url        https://www.codechef.com/problems/CANDYDIST
 * @solved     2026-09-15
 *
 * Problem
 * Accepted solution for Candy Distribution.
 *
 * Approach
 * Pending manual review. The submitted code is preserved exactly below.
 *
 * Complexity
 * Pending manual review.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, M;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N >> M;

	    if(N%M == 0 && (N / M) % 2 == 0){

	        cout << "Yes\n";

	    }

	    else{

	        cout << "No\n";

	    }

	}

	return 0;

}
