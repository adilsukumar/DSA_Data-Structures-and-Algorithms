/*
 * ============================================================================
 * CodeChef PAR2 - Parity                                    Difficulty: 295
 * ============================================================================
 * @platform   CodeChef
 * @id         PAR2
 * @title      Parity
 * @difficulty 295
 * @topics     Basic Math, Implementation
 * @pattern    Even/Odd Modulo Check
 * @url        https://www.codechef.com/problems/PAR2
 * @solved     2026-06-07
 *
 * PROBLEM
 *   You are given T independent test cases. Each test case is a single
 *   integer N. For each N, decide its parity: print "YES" if N is even,
 *   "NO" if N is odd.
 *     Example: N = 4 -> "YES"   (4 is even)
 *              N = 7 -> "NO"    (7 is odd)
 *
 * INTUITION
 *   Parity is just "is there a remainder when you halve the number." An
 *   integer is even exactly when it is divisible by 2, i.e. N % 2 == 0.
 *   The modulo operator gives that remainder directly (0 for even, non-zero
 *   for odd), so a single test decides the answer. No arithmetic beyond one
 *   division-remainder is needed -- this is the definition of even, not a
 *   trick.
 *
 * WALKTHROUGH
 *   Line by line:
 *     - cin >> T;                 read how many test cases follow.
 *     - for (i = 0; i < T; i++)   loop once per test case.
 *     - cin >> N;                 read this case's integer.
 *     - if (N % 2 == 0)           remainder 0 means even -> print "YES".
 *     - else                      any non-zero remainder means odd -> "NO".
 *   Note N is read fresh inside the loop, so each case is fully independent;
 *   nothing carries over between iterations.
 *
 *   Dry run on input:
 *       3
 *       4
 *       7
 *       10
 *   -> T = 3.
 *      i=0: N=4,  4 % 2 == 0  -> "YES"
 *      i=1: N=7,  7 % 2 == 1  -> "NO"
 *      i=2: N=10, 10 % 2 == 0 -> "YES"
 *   Output:
 *       YES
 *       NO
 *       YES
 *
 * COMPLEXITY
 *   Time:  O(T) -- one constant-work modulo test per test case, no inner work.
 *   Space: O(1) -- only T, N, and the loop counter are stored; output is
 *          streamed, nothing is buffered per case.
 *
 * EDGE CASES
 *   - N = 0: 0 % 2 == 0 -> "YES". Zero is even, which is correct.
 *   - Negative N (if the constraints ever allowed it): in C++, (-3) % 2 == -1,
 *     which is non-zero, so the code still classifies it as odd correctly.
 *     Even negatives like -4 give 0 -> "YES". So the == 0 test is robust to
 *     sign; a "== 1" test would NOT be. Good that this code compares to 0.
 *   - Large N: `int` holds up to ~2.1e9. If constraints exceeded that, N would
 *     overflow on read -- switch to `long long`. Fine for the stated limits.
 *   - The `endl` after each line flushes the stream every iteration. Harmless
 *     here (tiny T), but for very large T prefer "\n" to avoid flush overhead.
 *
 * This solution is already optimal: O(1) per query is the best possible, since
 * you must at least read each number. No better approach exists to flag.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N;

	cin >> T;

	

	for (int i = 0; i < T; i++){

	    cin >> N;

	    if(N%2 == 0){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

    return 0;

}
