/* =============================================================================
 * CodeChef JENGA - Jenga Night
 * Difficulty: 613 (Basic Math)
 *
 * @platform   CodeChef
 * @id         JENGA
 * @title      Jenga Night
 * @difficulty 613
 * @topics     Math
 * @pattern    Divisibility Check (X % N == 0)
 * @url        https://www.codechef.com/problems/JENGA
 * @solved     2026-07-19
 * =============================================================================
 *
 * PROBLEM
 *   A Jenga tower is built in complete levels, each level using exactly N
 *   blocks. You have X blocks in total. Decide whether those X blocks can be
 *   arranged into some whole number of complete levels using every block, with
 *   at least one level present. Print "YES" if possible, otherwise "NO".
 *
 *   Worked example:
 *     N = 3, X = 9  -> 9 blocks split as 3 levels of 3 -> YES
 *     N = 4, X = 9  -> 9 blocks leave a remainder of 1 -> NO
 *
 * INTUITION
 *   "Fill k complete levels of N blocks each" means the total X must equal k*N
 *   for some integer k >= 1. That is exactly the statement "X is a positive
 *   multiple of N": X leaves no remainder when divided by N (X % N == 0), AND
 *   X is large enough to form at least one level (X >= N). Both facts follow
 *   directly from the definition of divisibility, so no loop or construction is
 *   needed -- one modulo test settles it.
 *
 * WALKTHROUGH (this code)
 *   - `cin >> T;` reads the number of test cases.
 *   - The for-loop runs once per case, reading N (blocks per level) and
 *     X (blocks on hand) into the same two variables each iteration.
 *   - The guard `X >= N && X % N == 0`:
 *       * `%` binds tighter than `==`, which binds tighter than `&&`, so this
 *         parses as `(X >= N) && ((X % N) == 0)` -- the intended grouping.
 *       * `X % N == 0` is the core divisibility test.
 *       * `X >= N` is the meaningful extra guard: it rejects the X == 0 case,
 *         where X % N == 0 is trivially true but zero levels is not a valid
 *         tower. For any X >= N that is a multiple of N, both parts hold.
 *   - Prints "YES" / "NO" accordingly, one line per case.
 *
 *   Dry run on:
 *     T = 2
 *     Case 1: N = 3, X = 9  -> 9 >= 3 (true) and 9 % 3 == 0 (true)  -> "YES"
 *     Case 2: N = 4, X = 9  -> 9 >= 4 (true) but 9 % 4 == 1 != 0    -> "NO"
 *   Output:
 *     YES
 *     NO
 *
 * COMPLEXITY
 *   Time:  O(T) -- constant work (one comparison, one modulo) per test case.
 *   Space: O(1) -- only the scalars T, N, X are stored; no arrays.
 *
 * EDGE CASES
 *   - X == 0 (no blocks): X % N == 0 would say "yes", but the `X >= N` guard
 *     correctly forces "NO" (you cannot build a tower from nothing).
 *   - X == N (exactly one level): 1 level, remainder 0 -> "YES". Handled.
 *   - X < N (fewer blocks than one level): `X >= N` is false -> "NO". Handled.
 *   - N == 0 would make X % N undefined (division by zero); the code assumes
 *     the constraints guarantee N >= 1, which is standard for this problem.
 *   - `endl` flushes on every line; harmless here, but "\n" would be marginally
 *     faster for very large T. Not a correctness issue.
 *
 * This solution is already optimal (O(1) per query, single modulo); no better
 * approach exists.
 * ============================================================================= */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N >> X;

	    if(X >= N && X%N == 0){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

    return 0;

}
