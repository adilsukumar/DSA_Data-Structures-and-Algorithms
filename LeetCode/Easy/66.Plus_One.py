"""
================================================================================
LeetCode 66 - Plus One                                            Difficulty: Easy
================================================================================
@platform   LeetCode
@id         66
@title      Plus One
@difficulty Easy
@topics     Array, Math
@pattern    Reverse Carry Propagation
@url        https://leetcode.com/problems/plus-one/
@solved     2026-06-15

PROBLEM
-------
You are given a non-negative integer represented as an array of its decimal
digits, most-significant digit first (e.g. [1,2,3] means 123). No leading zeros,
except the number 0 itself which is [0]. Add one to the number and return the
resulting digit array.
    [1,2,3]   -> 124        -> [1,2,4]
    [4,3,2,1] -> 4322       -> [4,3,2,2]
    [9]       -> 10         -> [1,0]
    [9,9]     -> 100        -> [1,0,0]

INTUITION
---------
This is exactly how you add 1 by hand: start at the rightmost digit and work
left, carrying only when a digit overflows. The crucial observation is that
adding 1 produces a carry ONLY when the current digit is 9 (9 -> 10). Any digit
0..8 simply becomes digit+1 with NO carry, which means once you increment such a
digit you are completely done -- nothing to the left can change. So the moment
you hit a non-9 you can increment and return immediately. A 9 is the only digit
that turns into 0 and pushes the carry one place further left.

The only case where the carry escapes past the front of the array is when EVERY
digit was a 9 (e.g. 999 -> 1000). At that point the whole array has been zeroed
out and you just need to prepend a leading 1.

WALKTHROUGH
-----------
- `for i in range(len(digits)-1, -1, -1)`: scan indices right-to-left, from the
  last (least significant) digit toward the first.
- `if digits[i] == 9: digits[i] = 0`: this digit overflows. Set it to 0 and let
  the loop continue to the next-left digit -- that continuation IS the carry.
- `else: digits[i] += 1; return digits`: no overflow, so bump this digit and
  return at once. Every digit to the left is untouched and correct, so there is
  no reason to keep looping.
- `return [1] + digits`: reached only if the loop never returned early, i.e.
  every digit was 9 and is now 0. Prepend the escaped carry as a new leading 1.
  Note this builds a NEW list (list concatenation), which is fine and necessary
  since the result is one element longer than the input.

Dry run on [2, 9, 9]  (the number 299, expect 300 -> [3,0,0]):
    i=2: digits[2]==9  -> set to 0           digits = [2, 9, 0]
    i=1: digits[1]==9  -> set to 0           digits = [2, 0, 0]
    i=0: digits[0]==2  (not 9) -> +1, return digits = [3, 0, 0]   <-- returned
Result: [3, 0, 0]. Correct.

Dry run on [9, 9]  (the number 99, expect 100 -> [1,0,0]):
    i=1: digits[1]==9 -> set to 0            digits = [9, 0]
    i=0: digits[0]==9 -> set to 0            digits = [0, 0]
    loop ends without returning
    return [1] + [0, 0]                      -> [1, 0, 0]   <-- returned
Result: [1, 0, 0]. Correct.

COMPLEXITY
----------
Time  : O(n), n = number of digits. Worst case (all 9s) touches every digit once;
        the final `[1] + digits` is another O(n) copy but does not change the
        class. Best case (last digit < 9) is O(1).
Space : O(1) extra in the common case -- digits are mutated in place. Only the
        all-9s case allocates a new O(n) list for the extra leading digit.
        (Output array itself is not counted as auxiliary space.)

EDGE CASES
----------
- All nines ([9], [9,9,9]): handled by the post-loop `[1] + digits`; the array is
  fully zeroed then a leading 1 is prepended. This is the one branch that grows
  the output length.
- Single digit [0]: i=0, 0 != 9, becomes 1, returns [1]. Correct.
- Last digit not 9 (the common path): returns on the first iteration in O(1).
- Input is never empty per constraints, so the loop always executes at least once
  and `digits[i]` is always a valid access -- no bounds risk.

This solution is already optimal in both time and space; there is no faster or
lighter approach.
"""

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits)-1, -1, -1):
            if digits[i] == 9:
                digits[i] = 0
            else:
                digits[i] += 1
                return digits
        return [1] + digits
