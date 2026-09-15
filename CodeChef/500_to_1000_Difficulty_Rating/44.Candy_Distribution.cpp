/*
 * CodeChef CANDYDIST - Candy Distribution [668]
 *
 * @platform   CodeChef
 * @id         CANDYDIST
 * @title      Candy Distribution
 * @difficulty 668
 * @topics     Basic Programming Concepts, Basic Math
 * @pattern    Mathematical
 * @url        https://www.codechef.com/problems/CANDYDIST
 * @solved     2026-09-15
 *
 * Problem
 * Accepted solution for Candy Distribution.
 *
 * Approach
 * The code checks if the number of candies (N) can be evenly distributed among M
 * friends such that each receives an even number. It verifies if M divides N and
 * if the quotient (N/M) is even, printing Yes if both conditions are met,
 * otherwise No.
 *
 * Complexity
 * Time: O(1) Space: O(1)
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
