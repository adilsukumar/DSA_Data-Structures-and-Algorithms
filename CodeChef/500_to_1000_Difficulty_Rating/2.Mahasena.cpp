/* ============================================================================
 * CodeChef AMR15A - Mahasena                                  Difficulty: 533
 * ----------------------------------------------------------------------------
 * @platform   CodeChef
 * @id         AMR15A
 * @title      Mahasena
 * @difficulty 533
 * @topics     Conditional Statements, Basic Math, Implementation
 * @pattern    Parity of Sum via Odd Count (BUGGY here)
 * @url        https://www.codechef.com/problems/AMR15A
 * @solved     2026-06-09
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   An army has N weapons, each with an integer power A[i]. The army is
 *   "READY FOR BATTLE" if the SUM of all weapon powers is EVEN; otherwise it is
 *   "NOT READY". Print the appropriate string.
 *     Example:  N = 3, A = [1, 2, 3]  ->  sum = 6 (even)  -> "READY FOR BATTLE"
 *               N = 2, A = [1, 2]     ->  sum = 3 (odd)   -> "NOT READY"
 *
 * INTUITION
 *   You never need the actual sum, only its parity. Adding an even number never
 *   flips parity; adding an odd number always flips it. So the sum is even iff
 *   the COUNT OF ODD elements is even. That is the whole problem:
 *       sum even  <=>  (number of odd elements) % 2 == 0
 *   The count of even elements is irrelevant to the answer.
 *
 * WALKTHROUGH (of THIS code)
 *   - Read N; loop N times reading each value into X.
 *   - Tally each value: X % 2 == 0 increments even_no, else odd_no.
 *   - Decision: prints "READY FOR BATTLE" when even_no > odd_no, else "NOT READY".
 *   The tallying is fine, but the DECISION IS WRONG. The problem depends on the
 *   parity of the odd count, NOT on whether evens outnumber odds. Comparing
 *   even_no > odd_no answers a different question entirely.
 *
 *   Dry run on the official-style sample  N = 3, A = [1, 2, 3]:
 *       i=0  X=1  odd   -> even_no=0 odd_no=1
 *       i=1  X=2  even  -> even_no=1 odd_no=1
 *       i=2  X=3  odd   -> even_no=1 odd_no=2
 *       decision: even_no(1) > odd_no(2)?  NO  -> prints "NOT READY"
 *   But the true sum is 1+2+3 = 6, which is EVEN, so the expected answer is
 *   "READY FOR BATTLE". This code produces the WRONG output here.
 *
 * COMPLEXITY
 *   Time  : O(N) - single pass reading and classifying each of the N values.
 *   Space : O(1) - only two counters and scalars are kept, regardless of N.
 *
 * EDGE CASES
 *   - Negative powers: C++ % can yield a negative remainder for negatives, but
 *     the != 0 vs == 0 split still classifies parity correctly, so tallying is safe.
 *   - N = 1: handled by the loop; but the flawed comparison still misjudges it
 *     (e.g. A=[2] -> even_no=1>odd_no=0 -> "READY", correct; A=[3] -> 0>1 false
 *     -> "NOT READY", correct by luck). Correctness here is coincidental, not sound.
 *   - Ties (even_no == odd_no): '>' treats a tie as "NOT READY", another symptom
 *     of using the wrong criterion rather than parity of the odd count.
 *
 * CORRECT / OPTIMAL APPROACH  (this solution is INCORRECT as written)
 *   Keep the O(N) single pass, but decide on the parity of the odd count. You
 *   don't even need even_no. Sketch:
 *
 *       int N, X, odd = 0;
 *       cin >> N;
 *       for (int i = 0; i < N; i++) { cin >> X; if (X & 1) odd++; }
 *       cout << (odd % 2 == 0 ? "READY FOR BATTLE" : "NOT READY");
 *
 *   This is O(N) time / O(1) space and returns the right answer on [1,2,3]
 *   (odd = 2, even count -> "READY FOR BATTLE").
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int N, X;

	int even_no = 0;

	int odd_no = 0;

	cin >> N;

	for(int i = 0; i < N; i++){

	    cin >> X;

	    if(X%2 == 0){

	        even_no++;

	    }

	    else{

	        odd_no++;

	    }

	}

	if(even_no > odd_no){

	    cout << "READY FOR BATTLE";

	}

	else{

	    cout << "NOT READY";

	}

	return 0;

}
