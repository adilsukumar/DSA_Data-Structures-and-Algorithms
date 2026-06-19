/*
 * ============================================================================
 * LeetCode 88 - Merge Sorted Array                                     [Easy]
 * ============================================================================
 * @platform   LeetCode
 * @id         88
 * @title      Merge Sorted Array
 * @difficulty Easy
 * @topics     Array, Two Pointers, Sorting
 * @pattern    Concatenate then full sort
 * @url        https://leetcode.com/problems/merge-sorted-array/
 * @solved     2026-06-19
 *
 * ---------------------------------------------------------------------------
 * PROBLEM
 * ---------------------------------------------------------------------------
 * You are given two sorted (non-decreasing) integer arrays. nums1 has length
 * m + n: the first m slots hold real values, the last n slots are zero-padding
 * placeholders. nums2 holds n real values. Merge nums2 into nums1 so that
 * nums1 ends up as one sorted array of m + n elements. The merge must happen
 * IN PLACE inside nums1 -- you don't return anything.
 *
 *   Example:
 *     nums1 = [1,2,3,0,0,0], m = 3
 *     nums2 = [2,5,6],       n = 3
 *     result (in nums1) = [1,2,2,3,5,6]
 *
 * The trailing zeros in nums1 are NOT data; they are just reserved room so the
 * answer has somewhere to live.
 *
 * ---------------------------------------------------------------------------
 * INTUITION
 * ---------------------------------------------------------------------------
 * The placeholder zeros mean nums1 is already sized to hold the final answer.
 * This code ignores the fact that both inputs are already sorted and takes the
 * blunt route: physically drop all of nums2's values into the reserved tail of
 * nums1, producing one array that contains every element (just out of order),
 * then let a general-purpose sort put everything in place.
 *
 * It works simply because after the copy, nums1 holds exactly the m + n values
 * that belong in the answer -- no more, no fewer -- so sorting them yields the
 * correct merged result. Correct, but it throws away the "already sorted" gift
 * and pays log-linear time for something achievable in linear time.
 *
 * ---------------------------------------------------------------------------
 * WALKTHROUGH
 * ---------------------------------------------------------------------------
 *   for (int i = 0; i < n; i++)
 *       nums1[m + i] = nums2[i];
 *       -> Copies nums2[0..n-1] into the reserved tail slots nums1[m..m+n-1],
 *          overwriting the zero placeholders. i is an offset into nums2, and
 *          m + i is the matching destination slot. After this loop nums1 holds
 *          all m + n real values, but the block from nums2 is just appended, so
 *          the array is generally unsorted at the seam.
 *
 *   sort(nums1.begin(), nums1.end());
 *       -> Sorts the ENTIRE nums1 (all m + n elements) ascending. Note it sorts
 *          the whole vector, not a subrange -- fine here because every slot now
 *          holds a genuine value, so there are no leftover zeros to corrupt.
 *
 *   Dry run on nums1=[1,2,3,0,0,0], m=3, nums2=[2,5,6], n=3:
 *     copy i=0: nums1[3]=2 -> [1,2,3,2,0,0]
 *     copy i=1: nums1[4]=5 -> [1,2,3,2,5,0]
 *     copy i=2: nums1[5]=6 -> [1,2,3,2,5,6]
 *     sort      ->            [1,2,2,3,5,6]   <- final answer
 *
 * ---------------------------------------------------------------------------
 * COMPLEXITY
 * ---------------------------------------------------------------------------
 *   Time : O((m + n) log(m + n))  -- the copy loop is O(n), but the full sort
 *                                    over all m + n elements dominates.
 *   Space: O(1) auxiliary          -- writes happen inside nums1; sort() is
 *                                    typically in-place (introsort), ignoring
 *                                    its O(log n) recursion stack.
 *
 * ---------------------------------------------------------------------------
 * EDGE CASES
 * ---------------------------------------------------------------------------
 *   - n == 0 (nothing to merge): the loop runs zero times, sort() re-sorts an
 *     already-sorted nums1 harmlessly. Correct.
 *   - m == 0 (nums1 is all placeholders): the loop copies all of nums2 into
 *     nums1[0..n-1], then sort() orders them. Correct.
 *   - Duplicate values across arrays (the 2 above): sorting keeps them, so
 *     duplicates are preserved. Correct.
 *   - The code relies on nums1.size() == m + n exactly; if nums1 had extra
 *     trailing zeros beyond m + n they would sort to the front and corrupt the
 *     result. The problem guarantees the sizing, so this is safe here.
 *
 * ---------------------------------------------------------------------------
 * BETTER APPROACH (this solution is NOT optimal)
 * ---------------------------------------------------------------------------
 * This ignores that both arrays are already sorted. The intended solution is a
 * three-pointer merge from the BACK of nums1, which is O(m + n) time and needs
 * no sort. Filling from the back is the trick: the tail slots are free space,
 * so we never overwrite an nums1 value we still need to read.
 *
 *   int i = m - 1, j = n - 1, k = m + n - 1;   // read m, read n, write pos
 *   while (j >= 0) {                            // until nums2 is exhausted
 *       if (i >= 0 && nums1[i] > nums2[j])
 *           nums1[k--] = nums1[i--];            // larger of the two goes last
 *       else
 *           nums1[k--] = nums2[j--];
 *   }
 *   // nums1's own leftovers (i >= 0) are already in place -- no action needed.
 *
 * Same O(1) space, but linear time and it uses the sortedness the inputs hand
 * you. Worth re-deriving from scratch before an interview.
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        for(int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }
};
