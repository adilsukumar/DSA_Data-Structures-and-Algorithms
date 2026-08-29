/*
 * ============================================================================
 *  CodeChef DOUBLERENT - Double Rent                         Difficulty: 234
 * ============================================================================
 *  @platform   CodeChef
 *  @id         DOUBLERENT
 *  @title      Double Rent
 *  @difficulty 234
 *  @topics     Math, Implementation
 *  @pattern    O(1) Arithmetic (multiply by 2)
 *  @url        https://www.codechef.com/problems/DOUBLERENT
 *  @solved     2026-06-05
 * ----------------------------------------------------------------------------
 *
 *  PROBLEM
 *    Read a single integer X (the base rent) and report the "double rent" for
 *    it -- i.e. twice that amount. There is no logic branch, no loop, and no
 *    per-test-case handling here: exactly one integer in, one integer out.
 *      Example: X = 500  ->  answer = 1000.
 *
 *  INTUITION
 *    "Double" is the whole task, so the answer is literally 2 * X. The only
 *    thing worth thinking about is representation: doubling is exact in integer
 *    arithmetic (no rounding, no fractions), so a single multiply is both
 *    correct and optimal. There is nothing cleverer to do -- any O(1) formula
 *    for this reduces to one arithmetic op.
 *
 *  WALKTHROUGH  (this code, line by line)
 *    - #include <bits/stdc++.h>  : pulls in the whole standard library. Fine
 *      for competitive use; heavier than needed (only <iostream> is used).
 *    - int X;                    : one signed 32-bit integer to hold the input.
 *    - cin >> X;                 : parse the single integer from stdin.
 *    - cout << X*2;              : compute 2*X and print it. NOTE: no trailing
 *      newline / "\n" and no endl. CodeChef's checker is normally tolerant of a
 *      missing final newline, so this passes, but adding "\n" is tidier and a
 *      safer habit for judges that are strict about output format.
 *
 *    Dry run on X = 500:
 *      step 1  cin >> X          -> X = 500
 *      step 2  X*2               -> 500 * 2 = 1000   (a temporary int)
 *      step 3  cout << 1000      -> stdout now holds "1000"
 *      program returns 0 implicitly (main falls off the end -> return 0).
 *
 *  COMPLEXITY
 *    Time  : O(1) -- one read, one multiply, one write; independent of X.
 *    Space : O(1) -- a single int variable; no containers allocated.
 *
 *  EDGE CASES
 *    - Large X: the result is stored in an int. If X exceeds ~1.07e9, then 2*X
 *      overflows 32-bit signed range (max 2,147,483,647) and the printed value
 *      is garbage. For this problem the constraints keep X small, so int is
 *      safe -- but if constraints allowed X up to 1e9+, promote to `long long`
 *      (cout << 2LL * X;) to be safe.
 *    - X = 0            -> prints 0. Correct.
 *    - Negative X       -> prints 2*X (still correct arithmetic); the problem's
 *      rent values are non-negative, so this shouldn't arise.
 *    - Missing newline  -> as noted above, cosmetically nonstandard but accepted
 *      here.
 *
 *  This solution is already optimal in time and space; the only refinements are
 *  cosmetic (drop bits/stdc++.h for <iostream>, add a trailing "\n", and use
 *  `long long` if constraints ever grow). No algorithmic improvement exists.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int X;

	cin >> X;

	cout << X*2;



}
