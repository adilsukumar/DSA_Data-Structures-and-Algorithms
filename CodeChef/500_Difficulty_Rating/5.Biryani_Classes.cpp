/*
 * ============================================================================
 * CodeChef BIRYANI - Biryani Classes            Difficulty: 257 (very easy)
 * ============================================================================
 * @platform   CodeChef
 * @id         BIRYANI
 * @title      Biryani Classes
 * @difficulty 257
 * @topics     Basic Programming, Implementation, Math
 * @pattern    Per-test multiply two integers
 * @url        https://www.codechef.com/problems/BIRYANI
 * @solved     2026-06-05
 *
 * PROBLEM
 * -------
 * There are T independent test cases. Each test case gives two integers X and
 * Y, and the answer is simply their product X * Y. (In the story: a batch of
 * X plates each holding Y servings -> X*Y total servings of biryani.)
 *
 *   Example:  T = 2
 *             3 4   -> 12
 *             5 5   -> 25
 *
 * INTUITION
 * ---------
 * There is no algorithm here at all -- the "answer" is defined as the product.
 * The only real skill being tested is the standard competitive-programming I/O
 * shape: read a count T, then loop T times reading a fixed set of inputs and
 * emitting one line of output per test. Getting that loop scaffold right is the
 * whole point of a 257-rated problem.
 *
 * WALKTHROUGH
 * -----------
 *   int T, X, Y;         declares the test count and the two per-test operands.
 *   cin >> T;            reads how many test cases follow.
 *   for(i = 1..T)        one iteration per test case (i is just a counter; its
 *                        value is never used, a 0-based loop would work equally).
 *       cin >> X;        read first operand of THIS test case.
 *       cin >> Y;        read second operand.
 *       cout << X*Y      compute the product and print it,
 *            << endl;    followed by a newline (endl also flushes the buffer).
 *
 *   Dry run on the example above:
 *     read T = 2
 *     i=1: read X=3, Y=4 -> print 3*4  = 12\n
 *     i=2: read X=5, Y=5 -> print 5*5  = 25\n
 *     loop ends, program returns 0 implicitly.
 *
 *   Note the two separate `cin >> X; cin >> Y;` statements are equivalent to a
 *   single `cin >> X >> Y;` -- whitespace and newlines between tokens are
 *   skipped automatically, so input layout (same line or separate lines) does
 *   not matter.
 *
 * COMPLEXITY
 * ----------
 *   Time  : O(T) overall -- constant work (one multiply, one print) per test.
 *   Space : O(1) -- three int variables reused across all iterations; no arrays.
 *
 * EDGE CASES
 * ----------
 *   - int overflow: this is the ONLY real risk. `int` holds ~2.1e9. If the
 *     constraints ever allow X,Y near 1e5 each, X*Y (up to 1e10) overflows a
 *     32-bit int and the product wraps to garbage. For this problem's small
 *     constraints int is fine, but the safe habit is `long long` for products.
 *   - Negative / zero values: multiplication handles them correctly with no
 *     special-casing (0 gives 0).
 *   - T = 0: the loop body never runs and nothing is printed -- correct.
 *
 * STYLE NOTE (not a bug)
 * ----------------------
 *   `endl` flushes the stream on every line. For huge T this can be slow;
 *   `"\n"` is the usual competitive choice. At this problem size it is
 *   irrelevant. The code is already optimal in time and space, so no better
 *   algorithm exists to offer -- the only improvement is defensive typing:
 *
 *       long long X, Y;   cin >> X >> Y;   cout << X * Y << "\n";
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	for(int i = 1; i <= T; i++){

	    cin >> X;

	    cin >> Y;

	    cout << X*Y << endl;

	}

}
