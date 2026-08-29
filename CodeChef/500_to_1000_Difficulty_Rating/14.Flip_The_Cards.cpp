/* ============================================================================
 * CodeChef - Flip The Cards                                    Difficulty 641
 * ----------------------------------------------------------------------------
 *   @platform   CodeChef
 *   @id         FLIPCARDS
 *   @title      Flip The Cards
 *   @difficulty 641
 *   @topics     Math, Ad-hoc
 *   @pattern    Answer = min(X, N-X)
 *   @url        https://www.codechef.com/problems/FLIPCARDS
 *   @solved     2026-07-26
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   There are N cards in a row. X of them are currently face-up, the
 *   remaining N - X are face-down. Each test case asks for a single count
 *   that depends only on how the N cards split into the "up" group (size X)
 *   and the "down" group (size N - X).
 *
 *   The value the judge wants is the size of the SMALLER of those two
 *   groups: min(X, N - X). Intuitively, that is the number of flips you
 *   would make if you always flip whichever side is in the minority to
 *   match the majority (matching pairs, balancing the two piles, etc.).
 *
 *   Example: N = 5, X = 2  ->  up = 2, down = 3  ->  answer = min(2,3) = 2.
 *            N = 6, X = 3  ->  up = 3, down = 3  ->  answer = 3.
 *            N = 4, X = 0  ->  up = 0, down = 4  ->  answer = 0.
 *
 * INTUITION
 *   The whole task collapses to one formula: min(X, N - X).
 *     - If N >= 2X, then X <= N - X, so the up-group is the smaller one -> X.
 *     - If N <  2X, then N - X < X, so the down-group is smaller -> N - X.
 *   Splitting on N >= 2X is just a hand-written way of picking the smaller
 *   of the two partitions without calling min(). It works because the
 *   crossover point where X == N - X is exactly N == 2X.
 *
 * WALKTHROUGH (this code)
 *   - Read T, loop T times.
 *   - Read N and X for each case.
 *   - First branch: if (N == X || X == 0) print 0. This is the case where
 *     one group is empty, so the smaller group is trivially 0.
 *   - Else, if (N >= 2*X) print X          (up-group is the minority),
 *          otherwise      print N - X      (down-group is the minority).
 *
 *   NOTE / DEAD CODE: the first branch is REDUNDANT. When X == 0 the
 *   "else" would compute min(0, N) = 0 via the N >= 2X path anyway, and
 *   when N == X the N >= 2X path is false (unless X==0) so it prints
 *   N - X = 0. So the entire if/else is just an unrolled min(X, N - X);
 *   `cout << min(X, N - X) << "\n";` produces identical output. The code
 *   is correct, the extra branch is harmless clutter. Also `endl` flushes
 *   every line -- fine here, but "\n" is faster for large T.
 *
 *   DRY RUN  (T = 3):
 *     N=5 X=2 : N==X? no. X==0? no. N>=2X -> 5>=4 true -> print 2.
 *     N=6 X=4 : N==X? no. X==0? no. N>=2X -> 6>=8 false -> print N-X = 2.
 *     N=4 X=4 : N==X? yes -> print 0.  (min(4,0)=0, consistent.)
 *
 * COMPLEXITY
 *   Time  : O(1) per test, O(T) overall -- a constant number of
 *           comparisons and one print per case.
 *   Space : O(1) -- only the scalars T, N, X are stored.
 *
 * EDGE CASES
 *   - X == 0            : no cards up -> 0. Handled by branch 1 (and by min).
 *   - X == N            : no cards down -> 0. Handled by branch 1.
 *   - X == N - X (even N, N == 2X) : N >= 2X is true, prints X, which equals
 *                        N - X, so the tie is resolved correctly.
 *   - Overflow: 2*X is computed as int. Safe for the stated constraints
 *     (small N), but if N, X could approach INT_MAX, 2*X would overflow --
 *     comparing as (N - X >= X) or using long long avoids that risk.
 *
 * (Solution is already time/space optimal -- no better approach to add,
 *  only the simplification to min(X, N - X) noted above.)
 * ==========================================================================*/

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, X;

	cin >> T;

	

	while(T--){

	    cin >> N >> X;

	    if(N == X || X == 0){

	        cout << 0 << endl;

	    }

	    else{

	        if(N >= 2*X){

	            cout << X << endl;

	        }

	        else{

	            cout << N-X << endl;

	        }

	    }

	}

	return 0;

}
