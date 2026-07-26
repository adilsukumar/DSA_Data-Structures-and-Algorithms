/* ============================================================================
 * LeetCode 1480 - Running Sum of 1d Array                        [Easy]
 * ----------------------------------------------------------------------------
 * @platform   LeetCode
 * @id         1480
 * @title      Running Sum of 1d Array
 * @difficulty Easy
 * @topics     Array, Prefix Sum
 * @pattern    In-Place Prefix Sum
 * @url        https://leetcode.com/problems/running-sum-of-1d-array/
 * @solved     2026-07-26
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   Given an array nums, return its "running sum", where the value at index i
 *   is the sum of every element from index 0 through i inclusive. Formally,
 *   result[i] = nums[0] + nums[1] + ... + nums[i].
 *
 *   Example:  nums = [1, 2, 3, 4]
 *             out  = [1, 3, 6, 10]
 *                     |  |  |  +-- 1+2+3+4
 *                     |  |  +----- 1+2+3
 *                     |  +-------- 1+2
 *                     +----------- 1
 *
 * INTUITION
 *   A running sum is a prefix sum. The naive idea is: for each i, add up all
 *   elements 0..i from scratch -- that repeats work and costs O(N^2).
 *
 *   The key observation is that each answer builds on the previous one:
 *       result[i] = result[i-1] + nums[i]
 *   Once we know the running sum up to i-1, the running sum up to i is just one
 *   more addition. So a single left-to-right sweep, carrying the accumulated
 *   total forward, is enough. WHY it works: prefix sums are defined by that
 *   exact recurrence, so computing them in order means every value we depend on
 *   is already finalized before we need it.
 *
 *   The extra trick here is doing it IN PLACE. Because we only ever read the
 *   slot immediately to the left (nums[i-1]), and that slot has already been
 *   converted into a running sum on the previous iteration, we can overwrite
 *   nums[i] safely without needing a separate output array.
 *
 * WALKTHROUGH (this code, line by line)
 *   int N = nums.size();          -- cache the length once.
 *   for(i = 1; i < N; i++)        -- start at index 1, NOT 0. Index 0 is
 *                                    already its own running sum (there is
 *                                    nothing to its left), so it stays as-is.
 *   nums[i] = nums[i] + nums[i-1];-- overwrite: the element at i becomes
 *                                    "itself plus the running sum ending at
 *                                    i-1". Since nums[i-1] was already turned
 *                                    into a running sum on the prior pass, this
 *                                    is exactly result[i] = result[i-1]+nums[i].
 *   return nums;                  -- nums has been mutated into the answer.
 *
 *   Dry run on nums = [3, 1, 2, 10, 1]:
 *     start:            [3, 1, 2, 10, 1]     (index 0 already correct: 3)
 *     i=1: 1 + 3  = 4   [3, 4, 2, 10, 1]
 *     i=2: 2 + 4  = 6   [3, 4, 6, 10, 1]
 *     i=3: 10 + 6 = 16  [3, 4, 6, 16, 1]
 *     i=4: 1 + 16 = 17  [3, 4, 6, 16, 17]
 *     return            [3, 4, 6, 16, 17]
 *
 * COMPLEXITY
 *   Time:  O(N) -- one pass, a single addition per element.
 *   Space: O(1) extra -- mutates the input in place; no auxiliary array. (The
 *          returned vector is the input itself, not a new allocation.)
 *
 * EDGE CASES
 *   - N == 1: the loop never runs (starts at i=1, condition 1 < 1 is false).
 *     The lone element is returned unchanged, which is correct.
 *   - N == 0 (empty): N = 0, loop body never executes, returns empty. Safe.
 *     Note nums[i-1] is only ever read for i >= 1, so index -1 is never touched.
 *   - Overflow: LeetCode's constraints (|nums[i]| <= 100, length <= 1000) keep
 *     the largest possible running sum at 100*1000 = 100000, well within int.
 *     For looser constraints you would widen the accumulator to long long.
 *
 * This solution is already optimal: O(N) time is a hard lower bound (every
 * element must be read at least once) and O(1) extra space cannot be beaten.
 * No better approach to flag.
 * ============================================================================ */

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int N = nums.size();
        for(int i = 1; i < N; i++){
            nums[i] = nums[i] + nums[i-1];
        }
        return nums;
    }
};
