/*
 * ─────────────────────────────────────────────────────────────────────────────
 *  LeetCode 26 · Remove Duplicates from Sorted Array                      Easy
 * ─────────────────────────────────────────────────────────────────────────────
 *  @platform   LeetCode
 *  @id         26
 *  @title      Remove Duplicates from Sorted Array
 *  @difficulty Easy
 *  @topics     Array, Two Pointers
 *  @pattern    In-Place Compaction (via std::unique)
 *  @url        https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * ─────────────────────────────────────────────────────────────────────────────
 *
 *  PROBLEM
 *  -------
 *  Given a SORTED array, remove duplicates IN PLACE so each unique value appears
 *  once. Return k, the number of unique values. The first k slots of nums must
 *  hold those unique values in order; whatever sits beyond index k is ignored by
 *  the judge.
 *
 *      nums = [0,0,1,1,1,2,2,3,3,4]
 *      ->  k = 5,  nums begins [0,1,2,3,4,_,_,_,_,_]
 *
 *  You may not allocate a second array -- O(1) extra space is required.
 *
 *  INTUITION
 *  ---------
 *  Sortedness is the whole gift here. In a sorted array, equal values are always
 *  ADJACENT. So detecting a duplicate never needs a set or a search -- you only
 *  ever compare each element to the one directly before it. That is what turns
 *  an O(n log n) or O(n)-space problem into an O(n) time, O(1) space scan.
 *
 *  WALKTHROUGH
 *  -----------
 *      auto it = std::unique(nums.begin(), nums.end());
 *      return it - nums.begin();
 *
 *  `std::unique` is the standard library's implementation of exactly the scan
 *  described above. Two things about it are commonly misunderstood, and both
 *  are the reason this two-line solution is correct:
 *
 *   1. IT REMOVES CONSECUTIVE DUPLICATES ONLY. It does not deduplicate an
 *      arbitrary array -- [1,2,1] would come back unchanged. It works here
 *      purely because the input is guaranteed sorted. Using it on unsorted data
 *      is a real bug, not a style issue.
 *
 *   2. IT DOES NOT SHRINK THE CONTAINER. std::unique cannot erase elements; it
 *      has no access to the vector, only to iterators. What it does is shift the
 *      unique values forward to the front and return an iterator to the new
 *      logical end. Everything from that iterator onwards is unspecified junk.
 *      In normal C++ you would pair it with erase -- the "erase-remove idiom":
 *          nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
 *      Here we deliberately DON'T erase, because LeetCode wants the array left
 *      in place and only asks for the count. The half-finished state that would
 *      normally be a bug is exactly what this problem asks for.
 *
 *      it - nums.begin()
 *  Subtracting two random-access iterators gives the distance between them --
 *  i.e. how many elements sit before the new logical end. That count IS k.
 *
 *  Dry run on [0,0,1,1,1,2,2,3,3,4]:
 *      std::unique compacts to  [0,1,2,3,4 | 1,2,3,3,4]   ('|' = returned iter)
 *      it - begin() = 5  ->  return 5    ✔
 *      The judge reads only nums[0..4] = [0,1,2,3,4]. Correct.
 *
 *  COMPLEXITY
 *  ----------
 *  Time : O(n)  -- std::unique makes exactly one pass, comparing each element to
 *                  its predecessor.
 *  Space: O(1)  -- compaction happens in place; no allocation.
 *
 *  EDGE CASES
 *  ----------
 *  - Empty array -> begin() == end(), unique returns begin(), distance 0. Fine.
 *  - All identical [2,2,2] -> compacts to [2], returns 1.
 *  - All distinct -> nothing moves, returns n.
 *
 *  ⚠ WORTH WRITING BY HAND TOO
 *  ---------------------------
 *  std::unique is the right call in production C++, but in an interview the
 *  point of this problem is the TWO-POINTER pattern underneath it, and "I'd call
 *  std::unique" usually gets a follow-up of "now implement it". The manual
 *  version is short:
 *
 *      int removeDuplicates(vector<int>& nums) {
 *          if (nums.empty()) return 0;
 *          int k = 1;                              // nums[0] is always unique
 *          for (int i = 1; i < nums.size(); i++)
 *              if (nums[i] != nums[k - 1])         // differs from last kept?
 *                  nums[k++] = nums[i];            // keep it, grow the prefix
 *          return k;
 *      }
 *
 *  Two pointers with distinct jobs:
 *      i = the READ pointer, visits every element once.
 *      k = the WRITE pointer, marks the end of the deduplicated prefix, and
 *          doubles as the answer.
 *  k only advances on a new value, so it always lags behind i -- which is why
 *  writing to nums[k] can never clobber an element i has not read yet. That
 *  fast/slow read/write pair is the same pattern as problem 27 (Remove Element)
 *  and 283 (Move Zeroes). Learn it once, reuse it constantly.
 * ─────────────────────────────────────────────────────────────────────────────
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = std::unique(nums.begin(), nums.end());
        return it - nums.begin();
    
    }
};
