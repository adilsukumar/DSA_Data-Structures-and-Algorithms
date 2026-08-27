/*
 * ============================================================================
 *  CodeChef AVGPROBLEM - Greater Average                        Difficulty 500
 * ============================================================================
 *  @platform   CodeChef
 *  @id         AVGPROBLEM
 *  @title      Greater Average
 *  @difficulty 500
 *  @topics     Basic Math, Implementation
 *  @pattern    Avoid-division integer comparison
 *  @url        https://www.codechef.com/problems/AVGPROBLEM
 *  @solved     2026-06-07
 * ----------------------------------------------------------------------------
 *
 *  PROBLEM
 *    For each of T test cases you are given three integers A, B, C.
 *    Print "YES" if the average of A and B is strictly greater than C,
 *    otherwise print "NO". The average of A and B is (A + B) / 2.
 *
 *    Example:  A = 5, B = 9, C = 6  ->  avg(5,9) = 7, and 7 > 6  ->  "YES"
 *              A = 4, B = 4, C = 5  ->  avg(4,4) = 4, and 4 < 5  ->  "NO"
 *
 *  INTUITION
 *    The naive test is: (A + B) / 2 > C. But dividing by 2 in integer
 *    arithmetic truncates, so a genuine average of 3.5 would collapse to 3
 *    and could flip the answer. The clean fix is to clear the fraction:
 *    multiply BOTH sides by 2. The comparison
 *
 *          (A + B) / 2  >  C          becomes          A + B  >  2 * C
 *
 *    which is exactly the test this code uses. Since A, B, C are integers,
 *    A + B and 2*C are integers too, so there is no rounding and no
 *    floating-point imprecision — the inequality is decided exactly. This
 *    is the core "compare fractions by cross-multiplying" trick, and it is
 *    why the solution is both correct and cheap.
 *
 *  WALKTHROUGH
 *    - `cin >> T;`                read how many test cases follow.
 *    - `for(i = 0; i < T; i++)`   loop once per test case.
 *    - `cin >> A; cin >> B; cin >> C;`  read the three integers of this case.
 *    - `if ((A+B) > 2*C)`         the exact, division-free average test.
 *        prints "YES" when A and B's average beats C.
 *    - `else` prints "NO".
 *    - `endl` flushes each line; fine for these tiny inputs.
 *
 *    Dry run on T = 2, then (5 9 6), then (4 4 5):
 *        T = 2
 *        i=0:  A=5 B=9 C=6 ->  A+B = 14,  2*C = 12,  14 > 12 true  -> "YES"
 *        i=1:  A=4 B=4 C=5 ->  A+B =  8,  2*C = 10,   8 > 10 false -> "NO"
 *        Output:
 *            YES
 *            NO
 *
 *  COMPLEXITY
 *    Time:  O(T)  — a fixed amount of work (two reads-into-compare) per case.
 *    Space: O(1)  — four scalar ints reused across all iterations; nothing
 *                   scales with T.
 *
 *  EDGE CASES
 *    - Strict vs. non-strict: the problem asks for average STRICTLY greater
 *      than C, and `>` (not `>=`) matches that. Equality (A+B == 2*C) prints
 *      "NO", which is correct.
 *    - Truncation bug avoided: because 2*C is used instead of (A+B)/2, odd
 *      sums like A+B = 7 are handled exactly (7 > 2*3=6 -> YES) rather than
 *      truncating 7/2 to 3.
 *    - Overflow: within int range only if A+B or 2*C exceeds ~2.1e9. For this
 *      problem's small constraints int is safe; if C could approach 1e9,
 *      promote to long long to keep 2*C from overflowing.
 *    - Negative values: the algebra holds for negatives too, since the
 *      multiply-by-2 step preserves the inequality direction (2 > 0).
 *
 *  This solution is already optimal — O(1) per query with exact integer
 *  arithmetic and no avoidable work. No better approach to flag.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, A, B, C;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> A;

	    cin >> B;

	    cin >> C;

	    if ((A+B) > 2*C){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

    return 0;

}
