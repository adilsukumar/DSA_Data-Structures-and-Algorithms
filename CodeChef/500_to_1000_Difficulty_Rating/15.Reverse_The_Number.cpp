/*
 * ============================================================================
 * CodeChef FLOW007 - Reverse The Number                        Difficulty: 588
 * ============================================================================
 * @platform   CodeChef
 * @id         FLOW007
 * @title      Reverse The Number
 * @difficulty 588
 * @topics     Modular Arithmetic, Division, Implementation, Basic Programming
 * @pattern    Digit-by-digit reversal via mod/div
 * @url        https://www.codechef.com/problems/FLOW007
 * @solved     2026-06-26
 *
 * ----------------------------------------------------------------------------
 * PROBLEM
 * ----------------------------------------------------------------------------
 *   Given T test cases, each a positive integer N, print N with its digits
 *   reversed. Trailing zeros of the input become leading zeros of the reversal
 *   and are simply dropped (that is the intended behaviour, not a bug).
 *
 *   Example:  N = 15789  ->  98751
 *             N = 120    ->  21     (the reversed "021" prints as 21)
 *
 * ----------------------------------------------------------------------------
 * INTUITION
 * ----------------------------------------------------------------------------
 *   A number in base 10 is a stack of digits. The units digit is the cheapest
 *   to reach: N % 10 peels it off, N / 10 discards it. So we can pop digits
 *   from the RIGHT of N one at a time.
 *
 *   We want those same digits pushed onto the LEFT-to-right of a new number.
 *   The trick "ans = ans * 10 + r" does exactly that: multiplying by 10 shifts
 *   everything already collected one place up, opening a units slot for the
 *   digit we just popped. Because we consume N's digits right-to-left and emit
 *   them into ans left-to-right, the order is flipped -- which is the reversal.
 *
 *   Why it works cleanly: the last digit we pop from N (its most significant
 *   digit) is the last one appended to ans, so it lands in ans's units place --
 *   the mirror position. Every digit ends up mirrored.
 *
 * ----------------------------------------------------------------------------
 * WALKTHROUGH (this code)
 * ----------------------------------------------------------------------------
 *   cin >> T;                 read the number of test cases
 *   while (T--) { ... }       run the loop body T times (post-decrement so the
 *                             body sees the current value, then T drops by 1)
 *     cin >> N;               read this case's number
 *     int ans = 0;            accumulator for the reversed value, reset per case
 *     while (N > 0) {         keep going until every digit is consumed
 *       int r = N % 10;         r = current units (rightmost) digit
 *       N = N / 10;             drop that digit from N (integer division)
 *       ans = ans * 10 + r;     shift ans up and append r as the new units digit
 *     }
 *     cout << ans << endl;    print the reversal for this case
 *
 *   Dry run on N = 15789:
 *     start:              ans = 0
 *     r=9  N=1578         ans = 0*10 + 9   = 9
 *     r=8  N=157          ans = 9*10 + 8   = 98
 *     r=7  N=15           ans = 98*10 + 7  = 987
 *     r=5  N=1            ans = 987*10 + 5 = 9875
 *     r=1  N=0  (loop end) ans = 9875*10+1 = 98751
 *     output: 98751
 *
 * ----------------------------------------------------------------------------
 * COMPLEXITY
 * ----------------------------------------------------------------------------
 *   Time  : O(d) per test case, where d = number of digits in N (d = log10 N).
 *           The inner loop runs once per digit. Total O(T * d).
 *   Space : O(1). Only a few int scalars; the reversal is built in place.
 *
 * ----------------------------------------------------------------------------
 * EDGE CASES
 * ----------------------------------------------------------------------------
 *   - Trailing zeros (e.g. 120 -> 21): reversed leading zeros vanish because a
 *     number has no leading zeros. This matches the problem's expectation.
 *   - N = 0: the while loop never runs, ans stays 0, prints 0. Correct, though
 *     FLOW007's constraints keep N >= 1 so this rarely matters.
 *   - Overflow risk: for a palindrome-ish or large input near 2^31-1
 *     (2147483647), the reversed value can exceed INT_MAX and overflow `int`
 *     (undefined behaviour). FLOW007's bound (N up to ~10^4/10^5 depending on
 *     the sub-version) keeps this safe here, but for a general "reverse an int"
 *     task use `long long` for both N and ans to be robust.
 *
 * This solution is already optimal for the task: O(digits) time, O(1) space,
 * no data structures. No better asymptotic approach exists -- you must read
 * every digit at least once. (The only hardening worth noting is widening the
 * types to long long, as flagged above.)
 * ============================================================================
 */

#include <iostream>

using namespace std;



int main() {

    int T;

    cin >> T;



    while (T--) {

        int N;

        cin >> N;

        

        int ans = 0;



        while (N > 0) {

            int r = N % 10;

            N = N / 10;

            ans = ans * 10 + r;

        }



        cout << ans << endl;

    }



    return 0;

}
