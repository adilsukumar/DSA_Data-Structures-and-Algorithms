/*
 * CodeChef MAXTASTE - Maximise The Tastiness [627]
 *
 * @platform   CodeChef
 * @id         MAXTASTE
 * @title      Maximise The Tastiness
 * @difficulty 627
 * @topics     Implementation, Basic Math
 * @pattern    Max of each pair, summed
 * @url        https://www.codechef.com/problems/MAXTASTE
 * @solved     2026-07-19
 *
 * Problem
 * Chef must build one dish by choosing exactly one item from each of two shelves.
 *
 * Approach
 * The two choices are completely independent: which item you take from shelf 1 has no
 * effect on shelf 2, and the total is just their sum. When two independent terms are
 * added, each is maximised on its own — there is no trade-off to balance.
 *
 * Complexity
 * Time: O(T) — a fixed amount of comparison/printing work per test case.
 * Space: O(1) — four scalars reused across every test; no arrays.
 *
 * Notes
 * - A == B (and/or C == D): handled.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, A, B, C, D;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> A >> B >> C >> D;

	    if(A >= B){

	        if(C >= D){

	            cout << A+C << endl;

	        }

	        else{

	            cout << A+D << endl;

	        }

	    }

	    else if(B >= A){

	        if(C >= D){

	            cout << B+C << endl;

	        }

	        else{

	            cout << B+D << endl;

	        }

	    }

	}

	return 0;

}
