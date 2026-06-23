/*
 * ============================================================================
 *  LeetCode 136 - Single Number                                    [Easy]
 * ============================================================================
 *  @platform   LeetCode
 *  @id         136
 *  @title      Single Number
 *  @difficulty Easy
 *  @topics     Array, Bit Manipulation
 *  @pattern    XOR Accumulation
 *  @url        https://leetcode.com/problems/single-number/
 *  @solved     2026-06-23
 * ----------------------------------------------------------------------------
 *
 *  PROBLEM
 *  -------
 *  Given a non-empty array where EVERY element appears exactly twice except
 *  for ONE element that appears exactly once, return that single element.
 *  The problem demands linear time and constant extra space.
 *
 *      nums = [4, 1, 2, 1, 2]  ->  4      (1 and 2 each cancel out)
 *      nums = [2, 2, 1]        ->  1
 *
 *  INTUITION
 *  ---------
 *  This rides on three properties of bitwise XOR (^):
 *      1. x ^ x = 0        a value XOR'd with itself vanishes
 *      2. x ^ 0 = x        XOR with 0 leaves a value unchanged
 *      3. XOR is commutative AND associative, so ORDER DOES NOT MATTER
 *
 *  XOR the whole array together. Every value that appears twice pairs up and
 *  cancels to 0 (property 1), no matter how far apart the two copies sit
 *  (property 3). What remains is 0 ^ (the lone value) = the lone value
 *  (property 2). That is the answer, with no hash set or sorting needed.
 *
 *  WALKTHROUGH
 *  -----------
 *  - `int repeat = 0;`
 *        The accumulator. Seeded with 0, the XOR identity, so the first
 *        element folds in cleanly (0 ^ nums[0] == nums[0]).
 *  - `for (int i = 0; i < nums.size(); i++)`
 *        A single linear pass over every index.
 *  - `repeat ^= nums[i];`
 *        Fold each element into the running XOR. Paired values annihilate
 *        each other across the pass; the unique one survives.
 *  - `return repeat;`
 *        After the pass, `repeat` holds only the un-cancelled value.
 *
 *  (Naming aside: `repeat` is a slightly misleading variable name -- it
 *   actually ends up holding the NON-repeating value. Functionally fine,
 *   but a name like `acc` or `result` would read truer on revision.)
 *
 *  DRY RUN on nums = [4, 1, 2, 1, 2]   (binary in brackets)
 *      start          repeat = 0000 (0)
 *      ^ 4 [0100]  ->  repeat = 0100 (4)
 *      ^ 1 [0001]  ->  repeat = 0101 (5)
 *      ^ 2 [0010]  ->  repeat = 0111 (7)
 *      ^ 1 [0001]  ->  repeat = 0110 (6)   <- the second 1 cancels the first
 *      ^ 2 [0010]  ->  repeat = 0100 (4)   <- the second 2 cancels the first
 *      return 4                             <- only the lone 4 remains
 *
 *  COMPLEXITY
 *  ----------
 *  Time  : O(n) -- exactly one pass, one O(1) XOR per element.
 *  Space : O(1) -- a single int accumulator, independent of input size.
 *  This meets the problem's linear-time / constant-space requirement; a
 *  hash-set counting approach would solve it too but costs O(n) space.
 *
 *  EDGE CASES
 *  ----------
 *  - Single-element array [7]: loop runs once, 0 ^ 7 = 7. Correct.
 *  - The unique value is 0: pairs still cancel to 0, and the surviving 0 is
 *    returned correctly -- XOR does not special-case zero.
 *  - Negative numbers: XOR operates on the raw two's-complement bit pattern,
 *    so pairing/cancellation works identically for negatives.
 *  - Empty array: the problem guarantees non-empty input; this code would
 *    return 0, but that input is out of contract.
 *  - `int i` vs `nums.size()`: size() is unsigned (size_t); comparing a
 *    signed int against it triggers a signed/unsigned warning. Harmless for
 *    realistic sizes, but a size_t loop index would silence it.
 *
 *  This solution is already optimal in both time and space; no better
 *  approach is warranted.
 * ============================================================================
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int repeat = 0;

        for(int i = 0; i < nums.size(); i++){
            repeat ^= nums[i];
        }
        return repeat;
    }
};
