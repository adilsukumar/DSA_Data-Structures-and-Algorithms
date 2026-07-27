/*
 * ============================================================================
 * LeetCode 1295 - Find Numbers With Even Number Of Digits          [Easy]
 * ============================================================================
 * @platform   LeetCode
 * @id         1295
 * @title      Find Numbers With Even Number Of Digits
 * @difficulty Easy
 * @topics     Array, Math
 * @pattern    Digit Counting via Division
 * @url        https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
 * @solved     2026-07-27
 *
 * ----------------------------------------------------------------------------
 * PROBLEM
 * ----------------------------------------------------------------------------
 * Given an array of integers `nums`, return how many of them contain an EVEN
 * number of digits.
 *
 *   Example: nums = [12, 345, 2, 6, 7896]
 *     12   -> 2 digits (even)   count it
 *     345  -> 3 digits (odd)
 *     2    -> 1 digit  (odd)
 *     6    -> 1 digit  (odd)
 *     7896 -> 4 digits (even)   count it
 *   Answer: 2
 *
 * ----------------------------------------------------------------------------
 * INTUITION
 * ----------------------------------------------------------------------------
 * The number of digits of a positive integer is how many times you can strip
 * off its last digit before nothing is left. Integer division by 10 removes
 * the trailing digit each time (7896 -> 789 -> 78 -> 7). So counting the
 * divisions-until-zero gives the digit count directly, no string conversion
 * and no log/pow floating-point math (which can misfire on rounding).
 *
 * WHY it works: for any n in [1, 9] we have n/10 == 0, so a single-digit
 * number performs zero divisions. Starting `digits` at 1 accounts for that
 * final surviving digit; every extra division adds one more.
 *
 * ----------------------------------------------------------------------------
 * WALKTHROUGH (this code, line by line)
 * ----------------------------------------------------------------------------
 *   count = 0                  running tally of even-digit numbers
 *   for each index i:          visit every element once
 *     digits = 1               assume at least one digit
 *     num    = nums[i]         work on a copy so nums stays intact
 *     while num / 10 != 0:     while stripping a digit still leaves something
 *       digits += 1            ...that surviving part is one more digit
 *       num /= 10              strip the last digit
 *     if digits % 2 == 0:      even digit count?
 *       count += 1             yes -> include it
 *   return count
 *
 *   Note the loop CONDITION is `num / 10 != 0`, i.e. it stops the moment the
 *   value drops to a single digit — that last digit is the one pre-counted by
 *   `digits = 1`. This is why the seed value is 1, not 0.
 *
 *   Dry run on num = 7896:
 *     digits=1, num=7896 | 7896/10=789 !=0 -> digits=2, num=789
 *     digits=2, num=789  | 789/10 =78  !=0 -> digits=3, num=78
 *     digits=3, num=78   | 78/10  =7   !=0 -> digits=4, num=7
 *     digits=4, num=7    | 7/10   =0        -> loop ends
 *     digits=4 is even   -> count += 1
 *
 * ----------------------------------------------------------------------------
 * COMPLEXITY
 * ----------------------------------------------------------------------------
 * Time : O(n * d) where n = nums.size() and d = max digit count.
 *        Per element the inner loop runs (#digits - 1) times; d is tiny and
 *        bounded (nums[i] <= 1e5 -> at most 6 digits), so this is effectively
 *        O(n) linear.
 * Space: O(1). Only scalar counters; the input is never copied wholesale.
 *
 * ----------------------------------------------------------------------------
 * EDGE CASES
 * ----------------------------------------------------------------------------
 * - Single-digit values (1..9): inner loop never runs, digits stays 1 (odd),
 *   correctly not counted. This is the case the `digits = 1` seed protects.
 * - Empty array: the for-loop body never executes, returns 0. Correct.
 * - Powers of ten (10, 100, ...): counted right; e.g. 100 -> 100/10=10 (loop),
 *   10/10=1 (loop), 1/10=0 (stop) -> digits=3.
 * - Constraints guarantee nums[i] >= 1, so no zero or negatives to worry about.
 *   If a 0 ever appeared it would be treated as 1 digit (correct); a negative
 *   would break the count, but the problem forbids them.
 *
 * This solution is already optimal in both time and space for the constraints;
 * no better asymptotic approach exists. (A micro-alternative is a branchless
 * range check against the known even-digit bands [10,99],[1000,9999],... but
 * it is not asymptotically faster and is harder to read.)
 * ============================================================================
 */

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int digits = 1;
            int num = nums[i];
            while(num / 10 != 0){
                digits += 1;
                num /= 10;
            }
            if(digits % 2 == 0){
                count += 1;
            }
        }
        return count;
    }
};
