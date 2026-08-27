/*
 * ============================================================================
 *  CodeChef CANDIVIDE - Candy Division            Difficulty: 289
 * ============================================================================
 *  @platform   CodeChef
 *  @id         CANDIVIDE
 *  @title      Candy Division
 *  @difficulty 289
 *  @topics     Conditional Statements, Basic Math
 *  @pattern    Divisibility Check (N mod 3)
 *  @url        https://www.codechef.com/problems/CANDIVIDE
 *  @solved     2026-06-07
 * ----------------------------------------------------------------------------
 *
 *  PROBLEM
 *  -------
 *  Chef has N candies and wants to split them EQUALLY among his 3 friends,
 *  with no candy left over and none broken. For each test case, print "YES"
 *  if an exact even split is possible, otherwise "NO".
 *
 *  Example:
 *      N = 9  -> 9 / 3 = 3 each, nothing left  -> YES
 *      N = 7  -> 7 / 3 = 2 each, 1 left over    -> NO
 *
 *  INTUITION
 *  ---------
 *  "Divide N into 3 equal whole parts" is exactly the definition of "N is
 *  divisible by 3". There is no need to actually compute the shares or
 *  search anything -- a single remainder test settles it. N % 3 == 0 means
 *  the division is exact (remainder 0); any other remainder (1 or 2) means
 *  at least one candy cannot be placed, so the answer is NO. This is the
 *  whole idea: reduce a word problem about distribution to one modulo check.
 *
 *  WALKTHROUGH
 *  -----------
 *  Line by line, what THIS code does:
 *    - `cin >> T;`            read the number of test cases.
 *    - `for i in 0..T-1`      loop once per test case.
 *    - `cin >> N;`            read this test case's candy count into N
 *                             (N is reused each iteration -- fine, we only
 *                             need the current value).
 *    - `if (N % 3 == 0)`      the single decision: is N a multiple of 3?
 *    - print "YES" / "NO"     branch output, each followed by endl.
 *
 *  Dry run on input:
 *      T = 3
 *      N values: 6, 5, 12
 *
 *      iter 0: N=6  -> 6 % 3 == 0  (true)  -> print "YES"
 *      iter 1: N=5  -> 5 % 3 == 2  (false) -> print "NO"
 *      iter 2: N=12 -> 12 % 3 == 0 (true)  -> print "YES"
 *
 *      Output:
 *          YES
 *          NO
 *          YES
 *
 *  The only mutating state across iterations is N (overwritten each read)
 *  and the loop counter i; nothing accumulates, so each answer is
 *  independent -- correct for per-test-case problems.
 *
 *  COMPLEXITY
 *  ----------
 *  Time:  O(T)  -- one read + one modulo + one print per test case; the work
 *                  per case is constant, so total is linear in the number of
 *                  test cases. Independent of the magnitude of N.
 *  Space: O(1)  -- only the scalars T, N, i are stored; no arrays or buffers
 *                  that grow with the input.
 *
 *  EDGE CASES
 *  ----------
 *  - N = 0: 0 % 3 == 0 -> YES. Mathematically consistent (0 splits into
 *    three empty shares); safe here since the loop reads whatever N is given.
 *  - Large N: `int` holds up to ~2.1e9. If the constraints allowed N beyond
 *    that, the read would overflow -- switch N to `long long` to be safe.
 *    For this problem's stated limits `int` is fine, but it's the one thing
 *    to double-check when reusing this template.
 *  - No input validation is needed: the loop count comes straight from T,
 *    so it reads exactly the promised number of values.
 *
 *  NOTE (style, not correctness)
 *  -----------------------------
 *  Using `endl` flushes the output buffer on every line. It is harmless at
 *  these tiny sizes, but for high-volume I/O prefer `"\n"` and add
 *  `ios_base::sync_with_stdio(false); cin.tie(nullptr);` at the top. The
 *  algorithm itself is already optimal -- O(1) per query is the best any
 *  solution can do, so there is no better approach to reach for.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N;

	cin >> T;

	

	for (int i = 0; i < T; i++){

	    cin >> N;

	    if (N%3 == 0){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}



}
