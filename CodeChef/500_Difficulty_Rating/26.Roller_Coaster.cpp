/*
 * CodeChef MINHEIGHT - Roller Coaster [285]
 *
 * @platform   CodeChef
 * @id         MINHEIGHT
 * @title      Roller Coaster
 * @difficulty 285
 * @topics     Implementation, Conditionals, Math
 * @pattern    Direct Threshold Comparison
 * @url        https://www.codechef.com/problems/MINHEIGHT
 * @solved     2026-06-07
 *
 * Problem
 * A roller coaster enforces a minimum-height rule.
 *
 * Approach
 * There is nothing to search or compute here: "at least" is literally the >= operator. The
 * only decision the problem hides is whether meeting the limit EXACTLY is allowed.
 *
 * Complexity
 * Time: O(T) overall — a constant amount of work (one comparison, one print) per test
 * case, nothing scales with the height values.
 * Space: O(1) — three scalar ints reused across every iteration; no arrays and no
 * accumulation.
 *
 * Notes
 * - Equality (X == H): handled correctly by `>=` — the person at exactly the minimum is
 *   allowed to ride.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, H;

	cin >> T;

	

	for (int i = 0; i < T; i++){

	    cin >> X;

	    cin >> H;

	    if(X >= H){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

}
