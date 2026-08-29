/*
 * ============================================================================
 *  CodeChef DISCUS - Discus Throw                              Difficulty: 622
 * ============================================================================
 *  @platform   CodeChef
 *  @id         DISCUS
 *  @title      Discus Throw
 *  @difficulty 622
 *  @topics     Conditional Statements, Basic Programming, Implementation
 *  @pattern    Max of Three via If/Else
 *  @url        https://www.codechef.com/problems/DISCUS
 *  @solved     2026-07-19
 *
 * ----------------------------------------------------------------------------
 *  PROBLEM
 * ----------------------------------------------------------------------------
 *  A discus thrower gets three attempts with distances A, B, and C. Their
 *  recorded result is the FARTHEST of the three throws. For each of T test
 *  cases, read A, B, C and print the maximum.
 *
 *  Example:  A=6  B=9  C=4   ->  answer 9 (the second throw is the farthest).
 *  Example:  A=5  B=5  C=1   ->  answer 5 (ties are fine; either 5 is "the max").
 *
 * ----------------------------------------------------------------------------
 *  INTUITION
 * ----------------------------------------------------------------------------
 *  "Best of three" is just "maximum of three numbers." A value is the answer
 *  exactly when it is >= both of the other two. The code checks each candidate
 *  in turn:
 *      - if A is >= B and >= C, A is a maximum;
 *      - else if B is >= A and >= C, B is a maximum;
 *      - otherwise C must be the maximum (nothing else was >= everything).
 *  Using >= (not >) is deliberate: on ties more than one branch could qualify,
 *  and >= guarantees at least one branch always fires, so control never falls
 *  through with no output. Whichever qualifying value is printed, its numeric
 *  value equals the true max, so ties are handled correctly.
 *
 * ----------------------------------------------------------------------------
 *  WALKTHROUGH (this code)
 * ----------------------------------------------------------------------------
 *  - `cin >> T;`                 read the number of test cases.
 *  - `for(i = 0; i < T; i++)`    loop once per test case.
 *  - `cin >> A >> B >> C;`       read the three throw distances.
 *  - `if (A >= B && A >= C)`     A dominates both others -> print A.
 *  - `else if (B >= A && B >= C)`A was not the max, so test B -> print B.
 *  - `else`                      neither A nor B dominated -> C is the max.
 *  - `cout << ... << endl;`      one answer per line.
 *
 *  Note: A, B, C are declared ONCE outside the loop and overwritten each
 *  iteration. That is safe here because all three are always re-read before
 *  they are used; no stale value survives into a later test case.
 *
 *  Dry run on T=2, then (3 8 8), then (10 2 7):
 *    Test 1: A=3 B=8 C=8
 *        A>=B? 3>=8 false            -> skip first branch
 *        B>=A && B>=C? 8>=3 && 8>=8  -> true  -> print 8
 *    Test 2: A=10 B=2 C=7
 *        A>=B && A>=C? 10>=2 && 10>=7-> true  -> print 10
 *    Output:
 *        8
 *        10
 *
 * ----------------------------------------------------------------------------
 *  COMPLEXITY
 * ----------------------------------------------------------------------------
 *  Time  : O(T)  - a fixed 2-4 comparisons per test case, T cases total.
 *  Space : O(1)  - four ints reused across all iterations; no arrays.
 *
 * ----------------------------------------------------------------------------
 *  EDGE CASES
 * ----------------------------------------------------------------------------
 *  - All three equal (5 5 5): first branch 5>=5 && 5>=5 is true -> prints 5.
 *  - Two-way tie for the max: >= lets the earlier-tested variable win; the
 *    printed number is still the correct maximum, so the answer is right.
 *  - Max is the third value (C): both earlier tests fail, and `else` prints C
 *    unconditionally - correct, because if C were not the largest, one of the
 *    earlier >= checks would have caught A or B.
 *  - `endl` flushes each line; fine for these input sizes, though '\n' would
 *    avoid needless flushing if T were very large.
 *  - Assumes input is well-formed (exactly 3 ints per case); no validation,
 *    which matches the problem's guarantees.
 *
 * ----------------------------------------------------------------------------
 *  NOTE ON STYLE (already optimal in complexity)
 * ----------------------------------------------------------------------------
 *  This is O(T) time / O(1) space - you cannot do asymptotically better, since
 *  every value must be read. The if/else ladder is fine, but the tagged topic
 *  "Inbuilt functions" hints at the shorter idiom the author was practicing:
 *      cout << max({A, B, C}) << '\n';   // C++11 initializer-list overload
 *  Same behavior, one line, harder to get a comparison direction wrong.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, A, B, C;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> A >> B >> C;

	    if(A >= B && A >= C){

	        cout << A << endl;

	    }

	    else if(B >= A && B >= C){

	        cout << B << endl;

	    }

	    else{

	        cout << C << endl;

	    }

	}

	return 0;

}
