"""
LeetCode 66 - Plus One [Easy]

@platform   LeetCode
@id         66
@title      Plus One
@difficulty Easy
@topics     Array, Math
@pattern    Reverse Carry Propagation
@url        https://leetcode.com/problems/plus-one/
@solved     2026-06-15

Problem
You are given a non-negative integer represented as an array of its decimal digits,
most-significant digit first (e.g.

Approach
This is exactly how you add 1 by hand: start at the rightmost digit and work left,
carrying only when a digit overflows. The crucial observation is that adding 1 produces
a carry ONLY when the current digit is 9 (9 -> 10).

Complexity
Time: O(n), n = number of digits.
Space: O(1) extra in the common case -- digits are mutated in place.

Notes
- All nines ([9], [9,9,9]): handled by the post-loop `[1] + digits`; the array is fully
  zeroed then a leading 1 is prepended.
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
