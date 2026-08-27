/* ============================================================================
 * CodeChef CHEFGAMES - Chefland Games                      Difficulty: 550
 * ----------------------------------------------------------------------------
 *   @platform   CodeChef
 *   @id         CHEFGAMES
 *   @title      Chefland Games
 *   @difficulty 550
 *   @topics     Basic Programming, Implementation, Conditionals
 *   @pattern    All-Equal Check via Conditional
 *   @url        https://www.codechef.com/problems/CHEFGAMES
 *   @solved     2026-06-14
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   For each of T test cases you are given four integers R1 R2 R3 R4 (four
 *   round scores / flags). You must classify the test case with a single
 *   two-way verdict. This code prints "IN" when ALL FOUR values are exactly 0,
 *   and "OUT" otherwise.
 *
 *   Worked example:
 *     0 0 0 0  -> "IN"   (every value is zero)
 *     0 0 1 0  -> "OUT"  (at least one value is non-zero)
 *
 *   NOTE (be honest): the four-inputs / "IN" vs "OUT" shape here is inferred
 *   from the code, not from a re-read of the statement. When revising, open the
 *   URL and confirm what R1..R4 mean and what the exact accepted output tokens
 *   are ("IN"/"OUT" here). If the judge expects e.g. "YES"/"NO" the logic below
 *   is right but the printed strings would need swapping.
 *
 * INTUITION
 *   The only decision is: "are all four numbers zero?" A conjunction of four
 *   equality tests answers that directly in O(1). No arithmetic, no data
 *   structures, no sorting -- the condition IS the whole solution. It works
 *   because logical AND is true only when every clause is true, which is
 *   exactly the "all four are 0" requirement.
 *
 * WALKTHROUGH (this code)
 *   - `cin >> T;`                 read the number of test cases.
 *   - `for(i = 0; i < T; i++)`    loop once per test case.
 *   - four separate `cin >> Rk;`  read R1, R2, R3, R4 (whitespace/newlines are
 *                                 skipped automatically, so reading them on one
 *                                 statement each vs. chained is equivalent).
 *   - `if(R1==0 && R2==0 && R3==0 && R4==0)`  the single guard: true only when
 *                                 no value is non-zero.
 *   - print "IN" on the true branch, "OUT" on the else branch, each followed
 *     by `endl`. The variables are reused every iteration -- no reset needed
 *     because all four are overwritten by fresh reads before the test.
 *
 *   Dry run, input:
 *     T = 2
 *     TC1: 0 0 0 0   -> guard is (T && T && T && T) = true  -> "IN"
 *     TC2: 5 0 0 0   -> guard is (F && ...)         = false -> "OUT"
 *   Output:
 *     IN
 *     OUT
 *
 * COMPLEXITY
 *   Time  : O(T)  -- constant work (4 reads + 4 comparisons) per test case.
 *   Space : O(1)  -- five int variables, reused across all iterations.
 *
 * EDGE CASES
 *   - All zero            -> "IN"          (handled by the conjunction).
 *   - Any single non-zero -> "OUT"         (AND short-circuits to false).
 *   - Negative inputs     -> compared with ==0 like any other value; a negative
 *                            counts as non-zero -> "OUT". Confirm the statement
 *                            actually allows negatives; if not, harmless.
 *   - Large magnitudes    -> `int` holds up to ~2.1e9; if the statement permits
 *                            values beyond that, switch to `long long`. At a 550
 *                            rating this is almost certainly unneeded.
 *   - T = 0               -> loop body never runs, no output. Correct.
 *
 * STYLE NOTE (not a bug)
 *   `endl` flushes the stream on every line; for large T, "\n" is faster. Not a
 *   correctness issue at this constraint size. Solution is already optimal in
 *   time and space -- no better asymptotic approach exists.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, R1, R2, R3, R4;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> R1;

	    cin >> R2;

	    cin >> R3;

	    cin >> R4;

	    

	    if(R1 == 0 && R2 == 0 && R3 == 0 && R4 == 0){

	        cout << "IN" << endl;

	    }

	    else{

	        cout << "OUT" << endl;

	    }

	}

    return 0;

}
