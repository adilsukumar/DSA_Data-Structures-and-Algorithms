/*
 * ============================================================================
 *  CodeChef - Air Conditioner Temperature                     Difficulty: 584
 * ============================================================================
 *  @platform   CodeChef
 *  @id
 *  @title      Air Conditioner Temperature
 *  @difficulty 584
 *  @topics     Basic Programming, Basic Math, Comparisons
 *  @pattern    Threshold check on max of two values
 *  @url        https://www.codechef.com/problems/ACTEMP
 *  @solved     2026-06-23
 *
 *  PROBLEM
 *  -------
 *  For each test case you are given three integers A, B, C. B acts as an
 *  upper limit (the temperature the AC can guarantee / a comfort ceiling),
 *  and A and C are two requested values that must BOTH stay within that
 *  limit. Print "Yes" if neither A nor C exceeds B, otherwise "No".
 *
 *  Reading it straight off the code: answer is "Yes" iff  A <= B  AND  C <= B.
 *
 *  Example:  A=20, B=25, C=22  -> both <= 25            -> "Yes"
 *            A=20, B=25, C=30  -> C(30) exceeds 25      -> "No"
 *
 *  INTUITION
 *  ---------
 *  Two independent conditions "A <= B" and "C <= B" can be folded into one:
 *  the *larger* of A and C is the only one that can break the ceiling. If the
 *  bigger of the two already fits under B, the smaller one trivially does too.
 *  So  (A <= B && C <= B)  is exactly equivalent to  max(A, C) <= B.
 *  That is why a single comparison against max(A,C) suffices -- it is not a
 *  shortcut that loses cases, it is a logically identical rewrite.
 *
 *  WALKTHROUGH
 *  -----------
 *    cin >> T;                 read the number of test cases
 *    while (T--) { ... }       loop exactly T times (post-decrement runs the
 *                              body while T is non-zero, then decrements)
 *    cin >> A >> B >> C;        read the three integers for this case
 *    if (max(A,C) <= B)         the whole decision, in one comparison
 *        cout << "Yes"          both values fit under the ceiling
 *    else
 *        cout << "No"           at least one of A, C is above B
 *    endl                       newline after each answer (also flushes)
 *
 *  Dry run on 2 test cases:  [ (20 25 22), (20 25 30) ]
 *    T = 2
 *    Case 1: A=20 B=25 C=22 -> max(20,22)=22, 22<=25 true  -> print "Yes"
 *    Case 2: A=20 B=25 C=30 -> max(20,30)=30, 30<=25 false -> print "No"
 *    T reaches 0, loop ends.
 *  Output:
 *    Yes
 *    No
 *
 *  COMPLEXITY
 *  ----------
 *  Time  : O(T) overall -- O(1) work per test case (one max + one compare).
 *  Space : O(1) -- only a handful of int scalars, reused each iteration.
 *
 *  EDGE CASES
 *  ----------
 *  - A == B or C == B: the "<=" is inclusive, so equal-to-ceiling counts as
 *    fitting -> "Yes". Correct if the limit is meant to be attainable.
 *  - A == C: max returns that common value; comparison still correct.
 *  - Order of A and C never matters because max() is symmetric, so swapping
 *    the two requested values cannot change the verdict.
 *  - int range: fine for the small constraints of a rating-584 problem; no
 *    overflow risk since only comparisons (no additions) are performed.
 *  - Minor performance note: endl flushes the buffer on every line. Harmless
 *    at these constraints, but "\n" would be marginally faster for huge T.
 *
 *  This solution is already optimal -- O(1) per query with no wasted work --
 *  so there is no better algorithmic approach to sketch.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, A, B, C;

	cin >> T;

	

	while(T--){

	    cin >> A >> B >> C;

    	if(max(A,C) <= B){

    	    cout << "Yes" << endl;

    	}

    	else{

    	    cout << "No" << endl;

    	}

	}

    return 0;

}
