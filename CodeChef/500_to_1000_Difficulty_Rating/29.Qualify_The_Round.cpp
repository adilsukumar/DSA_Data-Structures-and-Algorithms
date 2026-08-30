/*
 * CodeChef QUALIFY - Qualify The Round [594]
 *
 * @platform   CodeChef
 * @id         QUALIFY
 * @title      Qualify The Round
 * @difficulty 594
 * @topics     Arithmetic, Implementation
 * @pattern    O(1) Weighted Score Threshold Check
 * @url        https://www.codechef.com/problems/QUALIFY
 * @solved     2026-06-27
 *
 * Problem
 * You need at least X points to qualify a round.
 *
 * Approach
 * There is nothing to search or optimize: the score is a fixed linear combination of the
 * inputs. The whole problem is "compute a weighted sum and compare it to a threshold." The
 * only real content is knowing the weights (1 and 2) and that qualification is inclusive
 * (>=, not >), so hitting X exactly still qualifies.
 *
 * Complexity
 * Time: O(T) - constant work (one multiply-add + compare) per test case.
 * Space: O(1) - four int scalars, reused across iterations; no arrays.
 *
 * Notes
 * - Exact boundary (score == X): handled correctly by >= (inclusive).
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, A, B;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X >> A >> B;

	    if((A*1 + B*2) >= X){

	        cout << "Qualify" << endl;

	    }

	    else{

	        cout << "NotQualify" << endl;

	    }

	}

}
