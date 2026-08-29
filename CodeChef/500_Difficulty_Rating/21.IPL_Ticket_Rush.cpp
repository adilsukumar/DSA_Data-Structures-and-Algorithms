/*
 * ============================================================================
 * CodeChef IPLTRSH - IPL Ticket Rush          Difficulty: 273 (Beginner)
 * ============================================================================
 * @platform   CodeChef
 * @id         IPLTRSH
 * @title      IPL Ticket Rush
 * @difficulty 273
 * @topics     Basic Math, Implementation
 * @pattern    Clamped Subtraction (max(0, N-M))
 * @url        https://www.codechef.com/problems/IPLTRSH
 * @solved     2026-06-07
 *
 * ----------------------------------------------------------------------------
 * PROBLEM
 * ----------------------------------------------------------------------------
 *   T test cases. Each gives two integers N and M: N fans want a ticket, but
 *   only M tickets exist. Print how many fans are left WITHOUT a ticket.
 *   If there are enough (or extra) tickets, nobody is left out, so print 0.
 *
 *   Example:  N = 10 fans, M = 6 tickets  ->  10 - 6 = 4 fans miss out.
 *             N = 3  fans, M = 8 tickets  ->  everyone seated, answer 0
 *             (the 5 spare tickets are irrelevant; we never print a negative).
 *
 * ----------------------------------------------------------------------------
 * INTUITION
 * ----------------------------------------------------------------------------
 *   The answer is simply max(0, N - M). The only subtlety is the floor at 0:
 *   "fans without a ticket" can never be negative, so surplus tickets must NOT
 *   turn into a negative count. That is exactly what the if/else guards: it
 *   only performs the subtraction when N > M, and otherwise falls back to 0.
 *   Nothing more than one comparison and one subtraction per test case.
 *
 * ----------------------------------------------------------------------------
 * WALKTHROUGH (this code, line by line)
 * ----------------------------------------------------------------------------
 *   - `cin >> T;`                read the number of test cases.
 *   - `for (i = 0; i < T; i++)`  loop once per test case.
 *       - `cin >> N; cin >> M;`  read this case's fan count and ticket count.
 *       - `if (N > M)` -> print `N - M`   (the shortfall of tickets).
 *       - `else`       -> print `0`       (enough tickets, nobody left out).
 *   - `endl` flushes after each line; fine here, but see COMPLEXITY note.
 *
 *   Dry run on input:
 *       2          <- T = 2
 *       10 6       <- N=10, M=6
 *       3 8        <- N=3,  M=8
 *
 *     Iteration i=0: N=10, M=6. N>M is true -> print 10-6 = 4.
 *     Iteration i=1: N=3,  M=8. N>M is false -> print 0.
 *     Output:
 *       4
 *       0
 *
 * ----------------------------------------------------------------------------
 * COMPLEXITY
 * ----------------------------------------------------------------------------
 *   Time:  O(T)  - a constant amount of work (one compare, one subtract) per
 *                  test case, so total time is linear in the number of cases.
 *   Space: O(1)  - only a handful of scalar ints are held at once; no arrays.
 *
 * ----------------------------------------------------------------------------
 * EDGE CASES
 * ----------------------------------------------------------------------------
 *   - N == M (exactly enough tickets): N > M is false -> prints 0. Correct.
 *   - M > N (surplus tickets): else branch -> prints 0, never a negative.
 *   - N just above M (e.g. 1000000, 999999): prints 1. `int` holds values up
 *     to ~2.1e9, so as long as N and M fit in int (they do per constraints),
 *     N - M cannot overflow. Safe here.
 *   - The template comment "// your code goes here" is leftover boilerplate
 *     (dead text, harmless). The `int main()` implicitly returns 0.
 *
 * ----------------------------------------------------------------------------
 * NOTE: this solution is already optimal (O(T) time, O(1) space) - the logic
 * cannot be beaten. Two purely stylistic tightenings, not correctness fixes:
 *   - The if/else is exactly `cout << max(0, N - M) << "\n";` in one line.
 *   - `endl` forces a flush on every line; `"\n"` avoids that and is faster
 *     for large T, though for these tiny constraints it does not matter.
 * ----------------------------------------------------------------------------
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, M;

	cin >> T;

	for (int i = 0; i < T; i++){

	    cin >> N;

	    cin >> M;

	    if (N > M){

	        cout << N-M << endl;

	    }

	    else{

	        cout << 0 << endl;

	    }

	}



}
