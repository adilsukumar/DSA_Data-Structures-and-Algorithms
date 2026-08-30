/*
 * CodeChef CHEFGAMES - Chefland Games [550]
 *
 * @platform   CodeChef
 * @id         CHEFGAMES
 * @title      Chefland Games
 * @difficulty 550
 * @topics     Basic Programming, Implementation, Conditionals
 * @pattern    All-Equal Check via Conditional
 * @url        https://www.codechef.com/problems/CHEFGAMES
 * @solved     2026-06-14
 *
 * Problem
 * For each of T test cases you are given four integers R1 R2 R3 R4 (four round scores /
 * flags).
 *
 * Approach
 * The only decision is: "are all four numbers zero?" A conjunction of four equality tests
 * answers that directly in O(1). No arithmetic, no data structures, no sorting -- the
 * condition IS the whole solution.
 *
 * Complexity
 * Time: O(T) -- constant work (4 reads + 4 comparisons) per test case.
 * Space: O(1) -- five int variables, reused across all iterations.
 *
 * Notes
 * - All zero -> "IN" (handled by the conjunction).
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, R1, R2, R3, R4;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> R1;

	    cin >> R2;

	    cin >> R3;

	    cin >> R4;

	    

	    if(R1 == 0 && R2 == 0 && R3 == 0 && R4 == 0){

	        cout << "IN" << endl;

	    }

	    else{

	        cout << "OUT" << endl;

	    }

	}

    return 0;

}
