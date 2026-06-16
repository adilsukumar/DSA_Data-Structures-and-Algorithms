/*
 * ============================================================================
 * LeetCode 69 - Sqrt(x)                                              [Easy]
 * ============================================================================
 * @platform   LeetCode
 * @id         69
 * @title      Sqrt(x)
 * @difficulty Easy
 * @topics     Math, Binary Search
 * @pattern    Library sqrt() truncated to int
 * @url        https://leetcode.com/problems/sqrtx/
 * @solved     2026-06-16
 *
 * PROBLEM
 *   Given a non-negative integer x, return the square root of x rounded DOWN
 *   to the nearest integer (i.e. floor(sqrt(x))). The fractional part is
 *   discarded, and you may not use any built-in exponent/pow helper in the
 *   spirit of the problem.
 *     x = 8  -> 2   (sqrt(8) = 2.828..., floor = 2)
 *     x = 4  -> 2   (perfect square)
 *     x = 0  -> 0,  x = 1 -> 1
 *
 * INTUITION
 *   The answer is the largest integer r such that r*r <= x. This code sidesteps
 *   the algorithmic work entirely: it calls the C library's sqrt(), which
 *   computes the real-valued square root as a double, then relies on the
 *   implicit double->int conversion in `return` to TRUNCATE toward zero. For a
 *   non-negative result, truncation == floor, so the value that comes back is
 *   floor(sqrt(x)). It "works" because IEEE-754 doubles have a 52-bit mantissa,
 *   which can represent every 32-bit int exactly, and a conforming sqrt is
 *   correctly rounded -- so for the whole int range the double result is
 *   accurate enough that truncation lands on the right integer.
 *
 * WALKTHROUGH
 *   #include <cmath>          -> brings in std::sqrt (double overload).
 *   int mySqrt(int x)         -> x is promoted to double when passed to sqrt.
 *   return sqrt(x);           -> sqrt returns a double; the function's int
 *                               return type forces a narrowing conversion that
 *                               DROPS the fractional part (truncation), not
 *                               rounds it. That truncated integer is returned.
 *
 *   Dry run on x = 8:
 *     sqrt(8.0)      = 2.8284271247461903   (a double)
 *     return int(...) -> truncates to 2
 *     result         = 2                    (correct: 3*3=9 > 8, 2*2=4 <= 8)
 *
 *   Dry run on x = 2147483647 (INT_MAX):
 *     sqrt(2147483647.0) ~= 46340.9999...   (true floor is 46340, 46340^2 =
 *                                            2147395600 <= INT_MAX)
 *     return -> 46340                        correct.
 *
 * COMPLEXITY
 *   Time  : O(1) as written -- a single hardware/library sqrt call. (Note this
 *           "beats" the intended O(log x) binary-search bound only by delegating
 *           the real work to the standard library.)
 *   Space : O(1) -- no auxiliary storage.
 *
 * EDGE CASES
 *   x = 0, x = 1        : sqrt returns 0.0 / 1.0, truncates cleanly. OK.
 *   Perfect squares     : e.g. x = 2147395600 -> sqrt should give exactly
 *                         46340.0. Correctly rounded sqrt guarantees this for
 *                         values representable exactly as doubles (all ints
 *                         qualify), so no off-by-one here on a conforming libm.
 *   Negative input      : Out of scope per constraints (x >= 0); sqrt of a
 *                         negative double would yield NaN and an undefined int
 *                         conversion. Not guarded, but never exercised.
 *   Portability caveat  : The classic gotcha with `int(sqrt(x))` is that a
 *                         non-conforming or lower-precision sqrt can return a
 *                         value a hair below the true root for a perfect square
 *                         (e.g. 3.9999999 instead of 4.0), truncating to 3.
 *                         With double precision over the 32-bit range this does
 *                         not occur on standard libms, but if you ever widen
 *                         the range or use float, prefer an integer method.
 *
 * BETTER / INTENDED APPROACH (what an interviewer actually wants)
 *   This solution is correct but demonstrates none of the technique the problem
 *   is testing. In an interview, avoid sqrt() and use integer binary search on
 *   the answer, comparing with 64-bit multiplication to avoid overflow:
 *
 *     int mySqrt(int x) {
 *         long lo = 0, hi = x, ans = 0;
 *         while (lo <= hi) {
 *             long mid = lo + (hi - lo) / 2;
 *             if (mid * mid <= (long)x) { ans = mid; lo = mid + 1; }
 *             else                        hi = mid - 1;
 *         }
 *         return (int)ans;
 *     }
 *
 *   Runs in O(log x) with pure integer math -- no floating point, no rounding
 *   risk, and it shows the "search on the monotonic predicate r*r <= x" idea.
 *   Newton's method (r = (r + x/r) / 2 until convergence) is an even faster
 *   alternative worth mentioning.
 * ============================================================================
 */

#include <cmath>
class Solution {
public:
    int mySqrt(int x) {
        return sqrt(x);
    }
};
