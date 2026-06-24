/* ============================================================================
 * LeetCode 169 - Majority Element                                    [Easy]
 * ============================================================================
 * @platform   LeetCode
 * @id         169
 * @title      Majority Element
 * @difficulty Easy
 * @topics     Array, Hash Table, Divide and Conquer, Sorting, Counting
 * @pattern    Sort + Middle Element
 * @url        https://leetcode.com/problems/majority-element/
 * @solved     2026-06-24
 *
 * ---------------------------------------------------------------------------
 * PROBLEM
 * ---------------------------------------------------------------------------
 * Given an array `nums` of size n, return the "majority element" -- the value
 * that appears STRICTLY MORE than floor(n/2) times. The problem guarantees
 * such an element always exists, so there is no "not found" case to handle.
 *
 * Example:  nums = [2, 2, 1, 1, 1, 2, 2]   (n = 7)
 *   count(2) = 4, count(1) = 3.  4 > 7/2 = 3  ->  answer is 2.
 *
 * ---------------------------------------------------------------------------
 * INTUITION
 * ---------------------------------------------------------------------------
 * If one value occupies more than half the array, then after SORTING, that
 * value forms a single contiguous run longer than n/2. A run of length > n/2
 * is so long it must cover the center of the array no matter where it starts.
 *
 * Proof sketch: the run of the majority element spans some index window
 * [i, i + m - 1] with m > n/2. The earliest it can end is index m-1 >= n/2,
 * and the latest it can start is index n-m < n/2. So the window always
 * straddles index n/2. Therefore nums[n/2] is ALWAYS the majority element --
 * we don't even need to count anything.
 *
 * ---------------------------------------------------------------------------
 * WALKTHROUGH (this code, line by line)
 * ---------------------------------------------------------------------------
 *   sort(nums.begin(), nums.end());   // O(n log n) in-place ascending sort
 *   int half = nums.size()/2;         // integer division -> the center index
 *   return nums[half];                // the guaranteed-majority center value
 *
 * There is no counting loop and no verification -- correctness rides entirely
 * on the problem's guarantee that a majority element exists.
 *
 * Dry run on nums = [2, 2, 1, 1, 1, 2, 2]:
 *   after sort  -> [1, 1, 1, 2, 2, 2, 2]   (indices 0..6)
 *   half        -> 7 / 2 = 3
 *   nums[3]     -> 2                        <- correct
 *
 * Notice the run of 2's occupies indices 3..6 (length 4 > 3), so it swallows
 * the center index 3 regardless of how the values fell on either side.
 *
 * ---------------------------------------------------------------------------
 * COMPLEXITY
 * ---------------------------------------------------------------------------
 * Time  : O(n log n) -- dominated by the sort; the index lookup is O(1).
 * Space : O(1) auxiliary if the sort is in-place (introsort typically uses
 *         O(log n) recursion stack). The array itself is mutated in place.
 *
 * ---------------------------------------------------------------------------
 * EDGE CASES
 * ---------------------------------------------------------------------------
 * - Single element [x]: half = 0, returns x. Correct.
 * - Even n, e.g. [1,1,1,2] -> sorted stays [1,1,1,2], half=2, nums[2]=1. OK.
 *   (The half-index proof holds for both even and odd n.)
 * - Negative numbers / duplicates: irrelevant; sort handles ordering, and the
 *   center-index argument is value-agnostic.
 * - Caveat: this SIDE-EFFECTS the caller's array (it is sorted in place). If
 *   the caller depends on original order elsewhere, that's a hidden cost.
 * - It also trusts the "majority always exists" guarantee. If that guarantee
 *   were removed, nums[n/2] could return a non-majority value silently -- so
 *   this approach is only valid under the problem's stated promise.
 *
 * ---------------------------------------------------------------------------
 * BETTER / OPTIMAL APPROACH -- Boyer-Moore Voting (O(n) time, O(1) space)
 * ---------------------------------------------------------------------------
 * This solution is correct but not optimal: sorting costs O(n log n) when the
 * answer is obtainable in a single O(n) pass with no mutation. Boyer-Moore
 * keeps a running "candidate" and a balance counter; the majority element
 * survives because it outnumbers everything else combined.
 *
 *     int candidate = 0, count = 0;
 *     for (int x : nums) {
 *         if (count == 0) candidate = x;   // adopt a new candidate
 *         count += (x == candidate) ? 1 : -1;
 *     }
 *     return candidate;                     // guaranteed majority survives
 *
 * Intuition: every time two different values meet, they cancel (count--).
 * Since the majority appears > n/2 times, it can never be fully cancelled and
 * is whatever remains standing at the end. Prefer this for interviews -- it
 * hits the optimal bound and leaves the input untouched.
 * ========================================================================= */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int half = nums.size()/2;
        return nums[half];
    }
};
