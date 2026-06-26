/* ============================================================================
 * LeetCode 171 - Excel Sheet Column Number                         [Easy]
 * ----------------------------------------------------------------------------
 * @platform   LeetCode
 * @id         171
 * @title      Excel Sheet Column Number
 * @difficulty Easy
 * @topics     Math, String
 * @pattern    Base-26 Positional Decoding (Horner)
 * @url        https://leetcode.com/problems/excel-sheet-column-number/
 * @solved     2026-06-26
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   Excel labels its columns A, B, ..., Z, AA, AB, ..., AZ, BA, ...
 *   Given such a label, return its 1-based column number.
 *     A  -> 1      Z  -> 26     AA -> 27     AB -> 28     ZY -> 701
 *   Example: "AB" -> 28, because A contributes 1*26 and B contributes 2.
 *
 * INTUITION
 *   This is a positional number system, like decimal but base 26. In base 10
 *   the string "28" means 2*10 + 8. Here "AB" means 1*26 + 2 = 28. The only
 *   twist is that this is a BIJECTIVE base-26 system: there is no digit for
 *   zero. The digits run 1..26 (A..Z) instead of the usual 0..25. That is why
 *   we map each letter with (ch - 'A' + 1), giving A=1 .. Z=26, and never 0.
 *
 *   WHY it works: reading left to right, each new letter means "everything I
 *   have accumulated so far belongs to a higher place value, so shift it up by
 *   one digit (multiply by 26) and add the new digit." This is Horner's method
 *   for evaluating a polynomial in base 26 without ever computing powers of 26
 *   explicitly. No pow(), no reverse iteration, no per-position exponent.
 *
 * WALKTHROUGH
 *   int ans = 0;                              // accumulator, base-26 value so far
 *   for (char ch : columnTitle)               // scan digits most-significant first
 *       ans = ans * 26 + (ch - 'A' + 1);      // shift left one place, add this digit
 *   return ans;
 *
 *   The single line is the whole algorithm. ans*26 promotes the running total
 *   to the next place value; (ch - 'A' + 1) is the current digit in 1..26.
 *
 *   Dry run on "ZY" (expected 701):
 *     start        ans = 0
 *     ch = 'Z'     digit = 'Z'-'A'+1 = 26
 *                  ans = 0*26 + 26   = 26
 *     ch = 'Y'     digit = 'Y'-'A'+1 = 25
 *                  ans = 26*26 + 25  = 676 + 25 = 701
 *     return 701.                              // correct
 *
 *   Dry run on "AAA" (expected 703):
 *     ans=0 -> 'A': 0*26+1 = 1
 *           -> 'A': 1*26+1 = 27
 *           -> 'A': 27*26+1 = 703.             // correct
 *
 * COMPLEXITY
 *   Time  : O(n), n = length of columnTitle. One pass, O(1) work per char.
 *   Space : O(1). Only the integer accumulator; output is not counted.
 *
 * EDGE CASES
 *   - Single letter ("A"): loop runs once, ans = 0*26+1 = 1. Fine.
 *   - Largest LeetCode input "FXSHRXW" -> 2^31 - 1 = 2147483647. This is the
 *     max valid answer and it fits in a signed 32-bit int by exactly one, so
 *     `int ans` does NOT overflow within the problem's constraints. If inputs
 *     could exceed this range you would need `long`, but they cannot here.
 *   - Empty string: the constraints guarantee length >= 1, so this never
 *     occurs; if it did, the loop would not run and it would return 0.
 *   - Assumes input is uppercase A-Z only (guaranteed). Lowercase or other
 *     characters would produce a wrong digit; no validation is done, which is
 *     acceptable given the constraints.
 *
 * This solution is already optimal: a single O(n) pass, O(1) space, no
 * overflow within constraints. Nothing to improve.
 * ========================================================================== */

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;

        for (char ch : columnTitle) {
            ans = ans * 26 + (ch - 'A' + 1);
        }

        return ans;
    }
};
