/*
 * CodeChef FOURTICKETS - Four Tickets [302]
 *
 * @platform   CodeChef
 * @id         FOURTICKETS
 * @title      Four Tickets
 * @difficulty 302
 * @topics     Basic Math, Implementation
 * @pattern    Direct arithmetic comparison
 * @url        https://www.codechef.com/problems/FOURTICKETS
 * @solved     2026-06-10
 *
 * Problem
 * Chef wants to buy exactly 4 tickets for his family.
 *
 * Approach
 * The whole decision collapses to one inequality. Buying 4 identical tickets costs 4 * X.
 *
 * Complexity
 * Time: O(T) -- one multiply and one comparison per test case, nothing more.
 * Space: O(1) -- only the scalars T and X are stored; no arrays or buffers.
 *
 * Notes
 * - Exact budget (X = 250, total = 1000): the `<=` makes this "YES".
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    if(X*4 <= 1000){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

	return 0;

}
