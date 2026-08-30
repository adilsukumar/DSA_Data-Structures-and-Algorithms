/*
 * CodeChef FLIPCARDS - Flip The Cards [641]
 *
 * @platform   CodeChef
 * @id         FLIPCARDS
 * @title      Flip The Cards
 * @difficulty 641
 * @topics     Math, Ad-hoc
 * @pattern    Answer = min(X, N-X)
 * @url        https://www.codechef.com/problems/FLIPCARDS
 * @solved     2026-07-26
 *
 * Problem
 * There are N cards in a row.
 *
 * Approach
 * The whole task collapses to one formula: min(X, N - X). If N >= 2X, then X <= N - X, so
 * the up-group is the smaller one -> X.
 *
 * Complexity
 * Time: O(1) per test, O(T) overall -- a constant number of comparisons and one print per
 * case.
 * Space: O(1) -- only the scalars T, N, X are stored.
 *
 * Notes
 * - X == 0 : no cards up -> 0.
 * - The answer can be written directly as min(X, N - X).
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, X;

	cin >> T;

	

	while(T--){

	    cin >> N >> X;

	    if(N == X || X == 0){

	        cout << 0 << endl;

	    }

	    else{

	        if(N >= 2*X){

	            cout << X << endl;

	        }

	        else{

	            cout << N-X << endl;

	        }

	    }

	}

	return 0;

}
