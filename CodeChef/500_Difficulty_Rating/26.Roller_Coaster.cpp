/* ============================================================================
 * CodeChef MINHEIGHT - Roller Coaster                      Difficulty: 285
 * ----------------------------------------------------------------------------
 * @platform   CodeChef
 * @id         MINHEIGHT
 * @title      Roller Coaster
 * @difficulty 285
 * @topics     Implementation, Conditionals, Math
 * @pattern    Direct Threshold Comparison
 * @url        https://www.codechef.com/problems/MINHEIGHT
 * @solved     2026-06-07
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   A roller coaster enforces a minimum-height rule. For each of T independent
 *   test cases you are given two integers: a person's height and the minimum
 *   height the ride requires. Print "YES" if the person is tall enough to ride
 *   (height is at least the requirement), otherwise "NO".
 *
 *   Here the first value read (X) is treated as the person's height and the
 *   second (H) as the required minimum. The rule "can ride" == height >= limit.
 *
 *   Worked example:
 *     X = 150, H = 120  -> 150 >= 120  -> YES  (tall enough)
 *     X = 100, H = 140  -> 100 <  140  -> NO   (too short)
 *     X = 120, H = 120  -> 120 >= 120  -> YES  (exactly at the limit counts)
 *
 * INTUITION
 *   There is nothing to search or compute here: "at least" is literally the
 *   >= operator. The only decision the problem hides is whether meeting the
 *   limit EXACTLY is allowed. "Minimum height required" means the limit itself
 *   is acceptable, so the comparison must be >= (inclusive), not > (strict).
 *   Using > would wrongly reject a person standing exactly at the line. Each
 *   test case is fully independent, so a single per-line comparison suffices.
 *
 * WALKTHROUGH  (line by line)
 *   - `cin >> T;`                read the number of test cases.
 *   - `for (i = 0; i < T; i++)`  loop once per test case; i is only a counter,
 *                                its value is never used inside the body.
 *   - `cin >> X; cin >> H;`      read the two integers for this case in order:
 *                                X = person's height, H = required minimum.
 *   - `if (X >= H)`              the whole problem — inclusive threshold test.
 *   - `cout << "YES" << endl;`   print on its own line when tall enough...
 *   - `else cout << "NO" ...`    ...otherwise print NO.
 *   Note: X, H, T are reused each iteration; no state carries between cases,
 *   which is correct because the cases are independent.
 *
 *   Dry run on:
 *       3
 *       150 120
 *       100 140
 *       120 120
 *   T = 3.
 *     iter i=0: X=150 H=120 -> 150>=120 true  -> print "YES"
 *     iter i=1: X=100 H=140 -> 100>=140 false -> print "NO"
 *     iter i=2: X=120 H=120 -> 120>=120 true  -> print "YES"  (equality path)
 *   Output:
 *       YES
 *       NO
 *       YES
 *
 * COMPLEXITY
 *   Time  : O(T) overall — a constant amount of work (one comparison, one
 *           print) per test case, nothing scales with the height values.
 *   Space : O(1) — three scalar ints reused across every iteration; no arrays
 *           and no accumulation.
 *   Minor: `endl` flushes the output buffer on every line. Harmless for small
 *          T, but "\n" would avoid needless flushes if T were very large.
 *
 * EDGE CASES
 *   - Equality (X == H): handled correctly by `>=` — the person at exactly the
 *     minimum is allowed to ride. This is the one case a `>` bug would break.
 *   - Largest / smallest heights: values fit comfortably in `int`; no overflow
 *     since only a comparison is done, never a sum or product.
 *   - T = 0: the loop body never runs and nothing is printed — well defined.
 *   - Output casing: CodeChef accepts "YES"/"NO" for this task; the caps form
 *     used here is fine. (If a problem demanded exact "Yes"/"No", this would
 *     need changing — worth remembering as a general checker gotcha.)
 *   - `#include <bits/stdc++.h>` and the leftover "your code goes here" comment
 *     are GCC-only / cosmetic; neither affects correctness on CodeChef's judge.
 *
 * This solution is already optimal: O(1) per query is the theoretical floor for
 * a single-threshold check, so no better approach exists to sketch.
 * ==========================================================================*/

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, H;

	cin >> T;

	

	for (int i = 0; i < T; i++){

	    cin >> X;

	    cin >> H;

	    if(X >= H){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

}
