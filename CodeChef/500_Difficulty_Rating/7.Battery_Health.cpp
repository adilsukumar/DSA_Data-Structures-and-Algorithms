/*
 * ============================================================================
 * CodeChef BTRYHLTH - Battery Health                          Difficulty: 296
 * ============================================================================
 *   @platform   CodeChef
 *   @id         BTRYHLTH
 *   @title      Battery Health
 *   @difficulty 296
 *   @topics     Conditional Statements, Implementation
 *   @pattern    Single Threshold Comparison
 *   @url        https://www.codechef.com/problems/BTRYHLTH
 *   @solved     2026-06-07
 *
 * ----------------------------------------------------------------------------
 * PROBLEM
 * ----------------------------------------------------------------------------
 *   A phone battery is considered "healthy" if its health is at least 80%.
 *   For each of T independent test cases you are given an integer X (the
 *   battery health as a percentage). Print "YES" if the battery is healthy,
 *   otherwise "NO".
 *
 *   Example:  X = 80  -> "YES"  (80 clears the bar, boundary is inclusive)
 *             X = 79  -> "NO"
 *             X = 95  -> "YES"
 *
 * ----------------------------------------------------------------------------
 * INTUITION
 * ----------------------------------------------------------------------------
 *   There is nothing to compute or search here -- the answer is a direct
 *   function of a single number. The only thing that can trip you up is the
 *   boundary: "at least 80" means 80 itself counts, so the correct test is
 *   ">= 80", NOT "> 80". Using strict ">" would wrongly reject exactly 80,
 *   which is the classic off-by-one trap this problem is checking for.
 *   Each test case is independent, so we simply loop and decide each one on
 *   its own.
 *
 * ----------------------------------------------------------------------------
 * WALKTHROUGH
 * ----------------------------------------------------------------------------
 *   - `cin >> T;`            read how many test cases follow.
 *   - `for (i = 0; i < T)`   process each case exactly once; `i` is only a
 *                            counter, it is never used inside the body.
 *   - `cin >> X;`            read this case's battery health.
 *   - `if (X >= 80)`         the whole problem: inclusive threshold check.
 *   - print "YES" / "NO"     with `endl`, which also flushes the stream.
 *
 *   Dry run on:
 *       3
 *       80
 *       50
 *       100
 *
 *     T = 3.
 *     i=0: X=80  -> 80 >= 80 is true  -> print "YES"
 *     i=1: X=50  -> 50 >= 80 is false -> print "NO"
 *     i=2: X=100 -> 100 >= 80 is true -> print "YES"
 *     Loop ends. Output:  YES / NO / YES  (each on its own line).
 *
 * ----------------------------------------------------------------------------
 * COMPLEXITY
 * ----------------------------------------------------------------------------
 *   Time  : O(T)  -- one read and one constant-time comparison per test case.
 *   Space : O(1)  -- only the scalars T, X, i; nothing scales with input.
 *
 * ----------------------------------------------------------------------------
 * EDGE CASES
 * ----------------------------------------------------------------------------
 *   - Exactly 80: handled correctly because the comparison is inclusive
 *     (`>=`). This is the single most important case in the problem.
 *   - Minimum health (e.g. 0) or full health (100): both fall on the correct
 *     side of the same comparison, no special handling needed.
 *   - Case sensitivity: judge expects uppercase "YES"/"NO"; the code emits
 *     exactly those, so no verdict mismatch.
 *   - `int` is more than wide enough for a 0..100 percentage, so no overflow.
 *   - No malformed-input handling, but constraints guarantee well-formed input.
 *
 * ----------------------------------------------------------------------------
 * NOTE
 * ----------------------------------------------------------------------------
 *   This solution is already optimal -- O(T) time and O(1) space are the best
 *   possible when every input value must be read and answered. No better
 *   approach exists. Minor stylistic notes only: `endl` flushes on every line
 *   (harmless at this scale; `"\n"` would be marginally faster for huge T),
 *   and `#include <bits/stdc++.h>` pulls in the whole standard library when
 *   only <iostream> is used.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

    int T, X;

    cin >> T;

    

    for (int i = 0; i < T; i++){

        cin >> X;

        if(X >= 80){

            cout << "YES" << endl;

        }

        else{

            cout << "NO" << endl;

        }

    }

    return 0;

}
