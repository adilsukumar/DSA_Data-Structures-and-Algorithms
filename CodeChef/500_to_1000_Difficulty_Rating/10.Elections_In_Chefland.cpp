/* ============================================================================
 * CodeChef ELECTN - Elections In Chefland
 * Difficulty: 604 (Beginner)
 * ----------------------------------------------------------------------------
 * @platform   CodeChef
 * @id         ELECTN
 * @title      Elections In Chefland
 * @difficulty 604
 * @topics     Implementation, Loops, Conditional Statements
 * @pattern    Single-pass threshold counting
 * @url        https://www.codechef.com/problems/ELECTN
 * @solved     2026-06-28
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   For each test case you are given a count N and a threshold X, followed by
 *   N integers. You must report how many of those N integers are at least X
 *   (i.e. >= X). In the election framing, each of the N numbers is a vote
 *   tally and X is the bar that a tally must clear to be counted.
 *
 *   Worked example:
 *     N = 5, X = 100, values = [150, 90, 100, 40, 200]
 *     Values meeting "value >= 100": 150, 100, 200  ->  answer = 3
 *
 * INTUITION
 *   The answer is just a population count over a fixed predicate ("value >= X").
 *   There is no ordering, no relationship between the values, and each element
 *   is judged independently. So the moment a value is read, its contribution to
 *   the answer is fully known -- either it clears the bar (+1) or it does not.
 *   That means we never need to store the array at all: we can decide and
 *   discard each number on the fly. Reading-and-tallying in one pass is both
 *   the simplest and the optimal strategy here.
 *
 * WALKTHROUGH (this code)
 *   - `int T, N, X, Z;` declares the loop bounds and a single scratch variable
 *     Z that is reused to hold "the current value being read". Only Z needs to
 *     persist across the inner loop; the rest are per-test scalars.
 *   - `cin >> T;` reads the number of test cases.
 *   - The outer `for (i = 0; i < T; i++)` runs one iteration per test case.
 *   - `int count = 0;` resets the tally at the START of each test case. This
 *     reset is the critical correctness point -- if it lived outside the outer
 *     loop, counts would leak between test cases. It is correctly placed inside.
 *   - `cin >> N >> X;` reads this test case's element count and threshold.
 *   - The inner `for (j = 0; j < N; j++)` reads exactly N values, one at a time
 *     into Z, and does `if (Z >= X) count++;`. No array is allocated.
 *   - `cout << count << endl;` prints the tally for this test case.
 *
 *   Dry run on T=1, N=5, X=100, values = 150 90 100 40 200:
 *     count = 0
 *     Z=150 -> 150 >= 100  -> count = 1
 *     Z= 90 ->  90 >= 100? no -> count = 1
 *     Z=100 -> 100 >= 100  -> count = 2   (>= is inclusive, so equal counts)
 *     Z= 40 ->  40 >= 100? no -> count = 2
 *     Z=200 -> 200 >= 100  -> count = 3
 *     print 3
 *
 * COMPLEXITY
 *   Time:  O(N) per test case, O(sum of N) overall -- each value is touched
 *          exactly once, with O(1) work (one comparison) per value.
 *   Space: O(1) -- only a handful of scalars; the input is never stored.
 *
 * EDGE CASES
 *   - N = 0: the inner loop never executes, count stays 0, prints 0. Correct.
 *   - All values below X: count stays 0. Correct.
 *   - All values >= X: count reaches N. Correct.
 *   - Value exactly equal to X: counted, because the test is `>=` (inclusive).
 *     If the problem intended a strict "greater than", this would be off by
 *     one on ties -- worth re-checking the statement against the `>=` choice.
 *   - Overflow: count can be at most N; a 32-bit int is safe for typical N.
 *   - The `// your code goes here` line is a harmless leftover template comment
 *     (dead text, not dead code).
 *
 * NOTE
 *   This solution is already optimal in both time and space: any correct answer
 *   must read all N values at least once, so O(N)/O(1) cannot be beaten. The
 *   only micro-nit is using `endl` (which flushes) instead of `"\n"`; on large
 *   inputs `"\n"` plus `ios_base::sync_with_stdio(false)` is marginally faster,
 *   but it does not change the asymptotic cost.
 * ============================================================================ */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, X, Z;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    int count = 0;

	    cin >> N >> X;

	    for(int j = 0; j < N; j++){

	        cin >> Z;

            if (Z >= X){

                count ++;

            }

	    }

    cout << count << endl;

	}

}
