/* ==========================================================================
 * CodeChef CHEFONDATE - Chef On Date                       Difficulty: 294
 * --------------------------------------------------------------------------
 * @platform   CodeChef
 * @id         CHEFONDATE
 * @title      Chef On Date
 * @difficulty 294
 * @topics     Basic Programming, Conditionals, Implementation
 * @pattern    Direct Conditional Comparison
 * @url        https://www.codechef.com/problems/CHEFONDATE
 * @solved     2026-06-07
 * ==========================================================================
 *
 * PROBLEM
 *   Chef wants to go on a date. His date will only happen if he can afford it:
 *   he needs at least Y rupees, and he currently has X rupees. For each test
 *   case, print "YES" if Chef can go on the date, otherwise "NO".
 *   The date is affordable exactly when X >= Y (having exactly enough counts).
 *
 *   Example:
 *     X = 5, Y = 3  ->  5 >= 3  ->  "YES"
 *     X = 2, Y = 8  ->  2 <  8  ->  "NO"
 *     X = 4, Y = 4  ->  4 >= 4  ->  "YES"   (exact amount is enough)
 *
 * INTUITION
 *   This is not an algorithm problem at all -- it is a single yes/no decision
 *   per test case. The whole task reduces to one comparison, X >= Y. There is
 *   nothing to search, sort, or accumulate; the answer for each case is
 *   independent of every other case, so we just loop and compare. The only
 *   thing that needs care is the boundary: "at least Y" means the >= (not >),
 *   so equality must map to "YES". The code uses >=, which is correct.
 *
 * WALKTHROUGH (this code, line by line)
 *   - `int T, X, Y;`            declares the case count and the two inputs.
 *                               int is safe here: constraints keep X, Y within
 *                               a few thousand, far inside 32-bit range.
 *   - `cin >> T;`               reads how many test cases follow.
 *   - `for (i = 0; i < T; i++)` iterates once per test case. `i` is only a
 *                               counter; it is never used inside the body.
 *   - `cin >> X; cin >> Y;`     reads the two integers for this case. Two
 *                               separate extractions behave the same as one
 *                               `cin >> X >> Y;` -- whitespace/newlines are
 *                               skipped automatically.
 *   - `if (X >= Y)`             the single decision. True => affordable.
 *   - `cout << "YES" << endl;`  prints the affirmative and flushes.
 *   - `else cout << "NO" ...`   prints the negative otherwise.
 *
 *   Dry run on:
 *       T = 3
 *       5 3
 *       2 8
 *       4 4
 *
 *     read T=3
 *     i=0: read X=5, Y=3 -> 5>=3 true  -> print "YES"
 *     i=1: read X=2, Y=8 -> 2>=8 false -> print "NO"
 *     i=2: read X=4, Y=4 -> 4>=4 true  -> print "YES"
 *     loop ends (i=3 not < 3)
 *
 *   Output:
 *     YES
 *     NO
 *     YES
 *
 * COMPLEXITY
 *   Time  : O(T) -- one read plus one comparison per test case, and nothing
 *           inside the loop depends on the size of the values.
 *   Space : O(1) -- three int variables reused across all iterations; no
 *           arrays or containers are allocated.
 *
 * EDGE CASES
 *   - X == Y (exactly enough): handled correctly by >=, prints "YES".
 *     This is the classic trap; using > here would be the bug.
 *   - X much smaller / larger than Y: plain comparison, no overflow since the
 *     values are small and int-sized.
 *   - T == 0: the for-loop body never runs, nothing is printed -- correct.
 *   - Casing/format: judge expects exactly "YES"/"NO"; the code matches. Note
 *     the problem is typically case-insensitive, but exact uppercase is safest.
 *   - `endl` flushes on every line. For T this small that cost is irrelevant;
 *     for very high T, "\n" would avoid the repeated flush, but it is not a
 *     correctness issue here.
 *
 * NOTE
 *   This solution is already optimal: the problem inherently requires reading
 *   each case and emitting one comparison, so O(T) time / O(1) space cannot be
 *   beaten. No better approach exists; only micro-cleanups are possible
 *   (single `cin >> X >> Y;`, `"\n"` instead of `endl`, removing the unused
 *   loop-counter semantics), none of which change complexity or the verdict.
 * ==========================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

    int T, X, Y;

    cin >> T;

    

    for (int i = 0; i < T; i++) {

        cin >> X;

        cin >> Y;

        if (X >= Y){

            cout << "YES" << endl;

        }

        else{

            cout << "NO" << endl;

        }

    }

}
