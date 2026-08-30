/*
 * CodeChef BULLBEAR - Bull Or Bear [300]
 *
 * @platform   CodeChef
 * @id         BULLBEAR
 * @title      Bull Or Bear
 * @difficulty 300
 * @topics     Implementation, Conditionals, Basic Programming
 * @pattern    Three-way comparison per query
 * @url        https://www.codechef.com/problems/BULLBEAR
 * @solved     2026-06-10
 *
 * Problem
 * For each of T days you are given two prices: X (opening) and Y (closing).
 *
 * Approach
 * There is nothing to compute or remember across days. Each day is a wholly independent
 * question: "did the price go up, down, or stay flat?" That is a single sign comparison
 * between two numbers.
 *
 * Complexity
 * Time: O(T) -- constant work (two reads + up to two comparisons) per day.
 * Space: O(1) -- three ints reused for all days; no arrays or accumulation.
 *
 * Notes
 * - Equal prices (X == Y): handled by the `else`, never misreported as a profit or loss.
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

	    if(Y>X){

	        cout << "PROFIT" << endl;

	    }

	    else if(X>Y){

	        cout << "LOSS"<< endl;

	    }

	    else{

	        cout << "NEUTRAL" << endl;

	    }

	}

	return 0;

}
