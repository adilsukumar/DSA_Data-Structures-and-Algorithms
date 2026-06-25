/*
 * ============================================================================
 *  LeetCode 168 - Excel Sheet Column Title                          [Easy]
 * ============================================================================
 *
 *  @platform   LeetCode
 *  @id         168
 *  @title      Excel Sheet Column Title
 *  @difficulty Easy
 *  @topics     Math, String
 *  @pattern    Bijective Base-26 Conversion
 *  @url        https://leetcode.com/problems/excel-sheet-column-title/
 *  @solved     2026-06-25
 *
 * ----------------------------------------------------------------------------
 *  PROBLEM
 * ----------------------------------------------------------------------------
 *  Given a positive integer, return its Excel column title, the label shown at
 *  the top of a spreadsheet column.
 *      1 -> "A", 2 -> "B", ..., 26 -> "Z",
 *      27 -> "AA", 28 -> "AB", ..., 52 -> "AZ", 53 -> "BA", ...
 *  Example: convertToTitle(28) == "AB".
 *
 * ----------------------------------------------------------------------------
 *  INTUITION
 * ----------------------------------------------------------------------------
 *  This looks like base-26 conversion, but it is NOT ordinary base-26. A normal
 *  positional system has a digit for 0; here the smallest symbol 'A' maps to 1,
 *  and there is no symbol for 0. This is a "bijective" numeral system: every
 *  positive integer maps to exactly one string, with no leading-zero ambiguity.
 *
 *  The one trick that makes it work is the `columnNumber--` before taking the
 *  remainder. Shifting the value down by 1 re-centers the range from [1..26]
 *  onto [0..25], which lines up perfectly with the offsets 'A'..'Z'. Without
 *  that shift, a value like 26 would try to emit a "0" digit (there is none)
 *  and carry incorrectly. The decrement absorbs the "missing zero" at every
 *  level of the number, so the standard divide-and-mod loop then just works.
 *
 * ----------------------------------------------------------------------------
 *  WALKTHROUGH (line by line)
 * ----------------------------------------------------------------------------
 *    string result = "";              // built right-to-least-significant-first
 *    while (columnNumber > 0) {       // process one "digit" per iteration
 *        columnNumber--;              // 1-based -> 0-based: the key fix
 *        result = char(columnNumber % 26 + 'A') + result;
 *                                     // % 26 picks this position's letter;
 *                                     // prepend so most-significant ends left
 *        columnNumber /= 26;          // drop the digit we just consumed
 *    }
 *    return result;
 *
 *  Note the char is PREPENDED (letter + result), not appended, because we peel
 *  digits from least significant to most significant but read titles left(msd)
 *  to right(lsd).
 *
 *  DRY RUN on columnNumber = 28  (expect "AB")
 *    iter 1: 28 > 0
 *            --  -> 27
 *            27 % 26 = 1 -> 'A'+1 = 'B'   result = "B"
 *            27 / 26 = 1  -> columnNumber = 1
 *    iter 2: 1 > 0
 *            --  -> 0
 *            0 % 26 = 0 -> 'A'+0 = 'A'    result = "AB"
 *            0 / 26 = 0  -> columnNumber = 0
 *    loop ends -> return "AB"          correct.
 *
 *  Sanity check on a boundary, columnNumber = 26 (expect "Z"):
 *    --  -> 25; 25 % 26 = 25 -> 'Z'; 25 / 26 = 0; return "Z".
 *  Here the decrement is what stops 26 from wrongly becoming "A" + a carry.
 *
 * ----------------------------------------------------------------------------
 *  COMPLEXITY
 * ----------------------------------------------------------------------------
 *  Time  : O(log_26 n) - the value is divided by 26 each iteration, so the
 *          loop runs once per output letter (at most ~7 for a 32-bit int).
 *  Space : O(log_26 n) for the output string (O(1) auxiliary beyond it). The
 *          `letter + result` prepend rebuilds the string each step, but the
 *          total length is tiny, so this is not a practical concern.
 *
 * ----------------------------------------------------------------------------
 *  EDGE CASES
 * ----------------------------------------------------------------------------
 *  - Single letters (1..26): loop runs once; 26 -> "Z" handled by the shift.
 *  - Exact powers/boundaries (26 -> "Z", 52 -> "AZ", 702 -> "ZZ", 703 -> "AAA"):
 *    the decrement makes the "roll over" happen at Z, not at a phantom zero.
 *  - Problem guarantees columnNumber >= 1, so the loop always runs at least once
 *    and never returns "". Zero or negative input is out of contract and not
 *    handled (would return "" or misbehave), which is fine given the constraints.
 *  - No integer-overflow risk: values only shrink after the first divide.
 *
 * ----------------------------------------------------------------------------
 *  This solution is optimal: O(log n) time, minimal space, one clean pass.
 *  No better asymptotic approach exists.
 * ============================================================================
 */

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--;
            result = char(columnNumber % 26 + 'A') + result;
            columnNumber /= 26;
        }
        return result;
    }
};
