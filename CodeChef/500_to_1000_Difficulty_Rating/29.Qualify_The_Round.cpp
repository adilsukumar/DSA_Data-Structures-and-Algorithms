/*
 * ============================================================================
 * CodeChef - Qualify The Round                          Difficulty: 594
 * ============================================================================
 *   @platform   CodeChef
 *   @id         QUALIFY
 *   @title      Qualify The Round
 *   @difficulty 594
 *   @topics     Arithmetic, Implementation
 *   @pattern    O(1) Weighted Score Threshold Check
 *   @url        https://www.codechef.com/problems/QUALIFY
 *   @solved     2026-06-27
 *
 * ----------------------------------------------------------------------------
 * PROBLEM
 * ----------------------------------------------------------------------------
 *   You need at least X points to qualify a round. Points come from two kinds
 *   of solved problems:
 *     - A problems each worth 1 point
 *     - B problems each worth 2 points
 *   Your total score is therefore  A*1 + B*2.  Print "Qualify" if that total
 *   reaches X, otherwise "NotQualify". There are T independent test cases.
 *
 *   Worked example: X = 10, A = 4, B = 3
 *     score = 4*1 + 3*2 = 4 + 6 = 10  ->  10 >= 10  ->  "Qualify"
 *
 * ----------------------------------------------------------------------------
 * INTUITION
 * ----------------------------------------------------------------------------
 *   There is nothing to search or optimize: the score is a fixed linear
 *   combination of the inputs. The whole problem is "compute a weighted sum
 *   and compare it to a threshold." The only real content is knowing the
 *   weights (1 and 2) and that qualification is inclusive (>=, not >), so
 *   hitting X exactly still qualifies. Any per-test work beyond one
 *   multiply-add and one comparison would be wasted.
 *
 * ----------------------------------------------------------------------------
 * WALKTHROUGH
 * ----------------------------------------------------------------------------
 *   - Declare T (number of tests) and X, A, B reused each iteration.
 *   - Read T once.
 *   - Loop T times; each pass reads a fresh (X, A, B) triple.
 *   - Evaluate (A*1 + B*2) >= X:
 *       * A*1 is just A (the *1 is written for clarity / symmetry with B*2).
 *       * B*2 doubles the two-point problems.
 *       * >= makes an exact match qualify.
 *   - Print "Qualify" or "NotQualify" accordingly, one line per test.
 *
 *   Dry run on T=2:
 *     Test 1: X=10 A=4 B=3  -> 4 + 6 = 10;  10 >= 10 true  -> "Qualify"
 *     Test 2: X=7  A=2 B=1  -> 2 + 2 = 4;   4  >= 7  false -> "NotQualify"
 *   Output:
 *     Qualify
 *     NotQualify
 *
 * ----------------------------------------------------------------------------
 * COMPLEXITY
 * ----------------------------------------------------------------------------
 *   Time  : O(T)  - constant work (one multiply-add + compare) per test case.
 *   Space : O(1)  - four int scalars, reused across iterations; no arrays.
 *
 * ----------------------------------------------------------------------------
 * EDGE CASES
 * ----------------------------------------------------------------------------
 *   - Exact boundary (score == X): handled correctly by >= (inclusive).
 *   - A = 0 and B = 0: score 0; qualifies only if X <= 0, else "NotQualify".
 *   - Overflow: A*1 + B*2 is computed in int. Safe for the small constraints
 *     of this problem, but if A or B could approach ~10^9 this would overflow;
 *     using long long would be the defensive choice.
 *   - Output style: `endl` flushes the buffer every line. Harmless here given
 *     tiny T, but "\n" would be marginally faster on large inputs.
 *   - Dead-ish detail: the `*1` on A is a no-op kept only for readability.
 *
 * ----------------------------------------------------------------------------
 * NOTE ON OPTIMALITY
 * ----------------------------------------------------------------------------
 *   This is already optimal: O(1) per test is the theoretical floor since every
 *   input value must be read at least once. No better algorithm exists; only
 *   micro-tweaks apply (long long for safety, "\n" instead of endl).
 * ============================================================================
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
