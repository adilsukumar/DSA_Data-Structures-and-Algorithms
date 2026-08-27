/*
 * ─────────────────────────────────────────────────────────────────────────────
 *  LeetCode 35 · Search Insert Position                                   Easy
 * ─────────────────────────────────────────────────────────────────────────────
 *  @platform   LeetCode
 *  @id         35
 *  @title      Search Insert Position
 *  @difficulty Easy
 *  @topics     Array, Binary Search
 *  @pattern    Linear Scan (should be Binary Search)
 *  @url        https://leetcode.com/problems/search-insert-position/
 *  @solved     2026-06-13
 * ─────────────────────────────────────────────────────────────────────────────
 *
 *  PROBLEM
 *  -------
 *  Given a SORTED array of distinct integers and a target, return the index of
 *  the target if found. If not found, return the index where it WOULD be
 *  inserted to keep the array sorted.
 *
 *      [1,3,5,6], target 5  ->  2   (found at index 2)
 *      [1,3,5,6], target 2  ->  1   (would sit between 1 and 3)
 *      [1,3,5,6], target 7  ->  4   (belongs past the end)
 *
 *  The problem statement explicitly demands O(log n) runtime. Keep that in mind
 *  while reading the solution below -- this is the one thing it does not do.
 *
 *  INTUITION BEHIND THIS SOLUTION
 *  ------------------------------
 *  There is a neat observation that collapses both cases -- "found" and "insert
 *  here" -- into a single rule:
 *
 *      The answer is the index of the FIRST element that is >= target.
 *
 *  If that element equals the target, that index is where it was found. If it is
 *  greater, that is exactly where the target must be inserted to stay sorted.
 *  Same index either way, so one scan handles both.
 *
 *  WALKTHROUGH
 *  -----------
 *  for(int i = 0; i < nums.size(); i++){
 *      if(nums[i] == target) return i;        // exact hit
 *      else if(target < nums[i]) return i;    // first element bigger than
 *                                             // target -> insert right here
 *  }
 *  return nums.size();                        // target exceeds every element,
 *                                             // so it belongs at the very end
 *
 *  The two branches are really testing `nums[i] >= target` and could be written
 *  as one condition. The final `return nums.size()` is the "off the end" case
 *  and is easy to forget -- returning -1 or 0 there is a common wrong answer.
 *
 *  Dry run on [1,3,5,6], target = 2:
 *      i=0: nums[0]=1, not equal, 2 < 1 false  -> keep going
 *      i=1: nums[1]=3, not equal, 2 < 3 TRUE   -> return 1    ✔
 *
 *  Dry run on [1,3,5,6], target = 7:
 *      no element is >= 7, loop finishes -> return 4          ✔
 *
 *  COMPLEXITY
 *  ----------
 *  Time : O(n)  -- worst case (target at the end or beyond) touches every element.
 *  Space: O(1)
 *
 *  EDGE CASES
 *  ----------
 *  - Target smaller than everything -> returns 0 on the first comparison.
 *  - Target larger than everything  -> returns nums.size().
 *  - Single-element array -> handled by the same two branches.
 *
 *  ⚠ THIS SOLUTION IGNORES THE ACTUAL CONSTRAINT
 *  ---------------------------------------------
 *  The logic is correct and LeetCode will accept it, because n <= 10^4 here and
 *  a linear scan is fast enough to pass. But the problem asks for O(log n), and
 *  in an interview a linear scan on a SORTED array is treated as not having
 *  solved the problem -- the sortedness is the entire point, and this solution
 *  never uses it.
 *
 *  This is genuinely the most valuable problem in your set to redo, because it
 *  is the cleanest possible introduction to binary search -- and specifically to
 *  the "lower bound" variant, which is the form that actually shows up in harder
 *  problems (Search in Rotated Array, Find First and Last Position, Koko Eating
 *  Bananas, and the whole binary-search-on-answer family).
 *
 *  BINARY SEARCH VERSION -- O(log n)
 *  ---------------------------------
 *      int searchInsert(vector<int>& nums, int target) {
 *          int lo = 0, hi = nums.size();        // note: size(), NOT size()-1
 *          while (lo < hi) {                    // note: <, NOT <=
 *              int mid = lo + (hi - lo) / 2;    // overflow-safe midpoint
 *              if (nums[mid] < target) lo = mid + 1;  // answer is strictly right
 *              else                    hi = mid;      // mid might BE the answer
 *          }
 *          return lo;
 *      }
 *
 *  Four details worth internalising, because each is a classic bug source:
 *
 *   1. `hi = nums.size()`, not size() - 1. The answer can legitimately be n (the
 *      insert-at-the-end case), so n must be inside the searchable range. Think
 *      of the range as the GAPS between elements, not the elements themselves.
 *
 *   2. `while (lo < hi)`, not <=. With a half-open range [lo, hi), the search is
 *      finished when the window is empty, which is lo == hi.
 *
 *   3. `hi = mid` and not `mid - 1`. When nums[mid] >= target, mid itself is
 *      still a candidate answer, so it must stay in the range. Writing mid - 1
 *      here silently skips the correct answer.
 *
 *   4. `lo + (hi - lo) / 2` rather than `(lo + hi) / 2`. On large arrays the
 *      naive form can overflow int. This is the famous bug that sat undetected
 *      in the JDK's binary search for nine years.
 *
 *  When the loop ends, lo == hi == the index of the first element >= target --
 *  which is the same rule your linear scan uses, just found in log n steps
 *  instead of n. In production C++ this is `std::lower_bound(nums.begin(),
 *  nums.end(), target) - nums.begin()`.
 * ─────────────────────────────────────────────────────────────────────────────
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                return i;
            }
            else{
                if(target < nums[i]){
                    return i;
                }
            }
        }
        return nums.size();
    }
};
