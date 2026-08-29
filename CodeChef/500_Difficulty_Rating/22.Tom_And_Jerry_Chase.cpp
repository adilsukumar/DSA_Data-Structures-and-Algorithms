/*
 * ============================================================================
 * CodeChef JERRYCHASE - Tom And Jerry Chase          Difficulty: 298 (Beginner)
 * ============================================================================
 *
 * @platform   CodeChef
 * @id         JERRYCHASE
 * @title      Tom And Jerry Chase
 * @difficulty 298
 * @topics     Conditional Statements, Implementation, Basic Programming
 * @pattern    Single strict inequality per query
 * @url        https://www.codechef.com/problems/JERRYCHASE
 * @solved     2026-06-10
 *
 * ----------------------------------------------------------------------------
 * PROBLEM
 * ----------------------------------------------------------------------------
 * Tom is chasing Jerry. For each test case you are given two numbers that
 * describe the two mice (per the statement, X for Tom and Y for Jerry -- a
 * speed / head-start style quantity). Jerry escapes exactly when his value Y
 * is strictly greater than Tom's value X. Print "YES" if Jerry escapes,
 * otherwise "NO".
 *
 * The first line holds T, the number of test cases. Each of the next T lines
 * holds two integers X and Y.
 *
 *   Input                 Output
 *   3                     NO      (Y=4  not > X=5)
 *   5 4                   YES     (Y=7      > X=2)
 *   2 7                   NO      (Y=6  not > X=6, ties do NOT escape)
 *   6 6
 *
 * ----------------------------------------------------------------------------
 * INTUITION
 * ----------------------------------------------------------------------------
 * There is no algorithm to design here -- the whole problem collapses to one
 * comparison. The only decision that carries any subtlety is the boundary:
 * escape requires Y to *beat* X, not merely match it. So the correct test is
 * strict (Y > X), and the equal case (Y == X) must fall to "NO". Using ">"
 * instead of ">=" is the single thing that makes this correct; everything
 * else is I/O plumbing. Because each query is independent, we just loop T
 * times and answer each one in isolation.
 *
 * ----------------------------------------------------------------------------
 * WALKTHROUGH (this code, line by line)
 * ----------------------------------------------------------------------------
 *   - `cin >> T;`            read how many queries follow.
 *   - `for (i = 0..T-1)`     process each query independently; i is only a
 *                            counter, it is never used inside the body.
 *   - `cin >> X; cin >> Y;`  read Tom's value then Jerry's value for this case.
 *   - `if (Y > X)`           the strict inequality -- the crux of the problem.
 *                            True  -> print "YES" (Jerry escapes).
 *                            False -> the else prints "NO" (caught or tied).
 *   - `endl`                 emits the newline AND flushes the buffer each
 *                            time. Correct, but for large T "\n" would be
 *                            faster; flushing per line is needless work here.
 *
 * The line `// your code goes here` is a leftover template comment (dead
 * text). It is harmless but adds nothing; safe to delete on a re-read.
 *
 * Dry run on the example above:
 *   T = 3
 *   case 1: X=5, Y=4 -> 4 > 5 ? no  -> "NO"
 *   case 2: X=2, Y=7 -> 7 > 2 ? yes -> "YES"
 *   case 3: X=6, Y=6 -> 6 > 6 ? no  -> "NO"   (equality handled correctly)
 *   Output: NO / YES / NO
 *
 * ----------------------------------------------------------------------------
 * COMPLEXITY
 * ----------------------------------------------------------------------------
 * Time:  O(T)  -- constant work (one read pair + one compare) per test case.
 * Space: O(1)  -- only the scalars T, X, Y are held; nothing is stored across
 *                 iterations, so memory does not grow with T.
 *
 * ----------------------------------------------------------------------------
 * EDGE CASES
 * ----------------------------------------------------------------------------
 *   - Y == X (a tie): must be "NO". Handled correctly by the strict ">".
 *     This is the one place a beginner slip (using ">=") would fail.
 *   - Negative values or 0: `int` and ">" compare them fine; no assumption of
 *     positivity is baked in.
 *   - Value range: if the constraints ever exceed ~2.1e9, `int` would overflow
 *     -- switch X, Y to `long long`. For this problem's stated small limits,
 *     `int` is safe.
 *   - T == 0: the loop body never runs and nothing is printed -- correct.
 *
 * ----------------------------------------------------------------------------
 * NOTE ON OPTIMALITY
 * ----------------------------------------------------------------------------
 * Algorithmically this is already optimal: O(1) per query is the floor, you
 * cannot answer a comparison in less. The only refinements are cosmetic /
 * throughput, not complexity:
 *   - Replace `endl` with '\n' and add `ios_base::sync_with_stdio(false);`
 *     `cin.tie(nullptr);` for faster bulk I/O.
 *   - Drop the dead template comment.
 * Sketch:
 *     ios_base::sync_with_stdio(false); cin.tie(nullptr);
 *     int T; cin >> T;
 *     while (T--) { int x, y; cin >> x >> y; cout << (y > x ? "YES" : "NO") << '\n'; }
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    if(Y>X){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

	return 0;

}
