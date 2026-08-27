/* ============================================================================
 * CodeChef AGEING - Ageing                                    Difficulty: 299
 * ============================================================================
 *   @platform   CodeChef
 *   @id         AGEING
 *   @title      Ageing
 *   @difficulty 299
 *   @topics     Basic Math, Implementation
 *   @pattern    Constant Offset Per Query
 *   @url        https://www.codechef.com/problems/AGEING
 *   @solved     2026-06-10
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   You are given T independent test cases. Each test case is a single integer
 *   X. For each one, print X - 10. That is the entire transformation: a fixed
 *   subtraction of 10 applied to every input value.
 *
 *   (The story framing on CodeChef dresses this up -- e.g. converting a value
 *   under one convention to another that is consistently 10 lower -- but the
 *   arithmetic the judge checks is exactly "output X minus 10".)
 *
 *   Example:
 *       Input           Output
 *       3               (T = 3 test cases)
 *       25       ->     15
 *       10       ->     0
 *       100      ->     90
 *
 * INTUITION
 *   There is no algorithm to design here. The map from input to output is the
 *   affine function f(X) = X - 10, the same for every test case. The only real
 *   work is the standard competitive-programming scaffolding: read the count T,
 *   then loop that many times, transforming and printing each value. It "works"
 *   because the transformation is a pure per-element function with no state
 *   carried between test cases, so a plain loop suffices.
 *
 * WALKTHROUGH
 *   - `int T, X;`            declares the test-case count and the current value.
 *   - `cin >> T;`            reads how many queries follow.
 *   - `for(i = 0; i < T; i++)` iterates exactly T times, once per test case.
 *       - `cin >> X;`        reads this case's value.
 *       - `cout << X-10`     computes and prints the answer for this case.
 *       - `<< endl;`         emits a newline AND flushes the output buffer.
 *   - `return 0;`            normal successful exit.
 *
 *   Dry run on the example above (T = 3):
 *       i=0: X=25  -> prints "15"   (25 - 10)
 *       i=1: X=10  -> prints "0"    (10 - 10)  boundary: result is exactly 0
 *       i=2: X=100 -> prints "90"   (100 - 10)
 *       loop ends (i=3 fails i<T), program exits.
 *   No accumulator, no array -- each line is independent.
 *
 * COMPLEXITY
 *   Time  : O(T) -- one read, one subtraction, one print per test case; the
 *           per-case work is constant.
 *   Space : O(1) -- only the two scalars T and X are held; nothing scales
 *           with the number of test cases.
 *
 * EDGE CASES
 *   - X = 10  -> 0. Handled naturally; there is no special-casing needed.
 *   - X < 10  -> a negative result (e.g. X=3 gives -7). The code prints it as
 *     written; whether the judge expects negatives depends on the input
 *     constraints, which for this rating almost certainly guarantee X >= 10.
 *   - Large X near INT_MAX: `X - 10` cannot overflow a signed int (subtracting
 *     stays in range), so `int` is safe for the stated bounds.
 *   - `int T, X;` is left uninitialized, but both are assigned by `cin >>`
 *     before use, so there is no undefined-value read on any real input.
 *
 * NOTE (style, not correctness)
 *   Using `endl` flushes the stream on every line. For huge T this is slower
 *   than `'\n'`; here it is harmless but worth remembering as a habit. The
 *   `#include <bits/stdc++.h>` header is a GCC-only convenience and non-portable
 *   -- fine for CodeChef, avoid it in production code. The solution is already
 *   optimal for the problem (O(T) is the lower bound -- you must read every
 *   input), so no better algorithm exists; only these micro-tweaks apply.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    cout << X-10 << endl;

	}

	return 0;



}
