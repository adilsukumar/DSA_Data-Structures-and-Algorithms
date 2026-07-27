/* ============================================================================
 * LeetCode 217 - Contains Duplicate                                [Easy]
 * ----------------------------------------------------------------------------
 * @platform   : LeetCode
 * @id         : 217
 * @title      : Contains Duplicate
 * @difficulty : Easy
 * @topics     : Array, Hash Table, Sorting
 * @pattern    : Hash set size comparison
 * @url        : https://leetcode.com/problems/contains-duplicate/
 * @solved     2026-07-27
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   Given an integer array `nums`, return true if ANY value appears at least
 *   twice, and false if every element is distinct.
 *     nums = [1,2,3,1] -> true   (the value 1 repeats)
 *     nums = [1,2,3,4] -> false  (all distinct)
 *
 * INTUITION
 *   A set stores only distinct keys: inserting a value that is already present
 *   is silently ignored. So if you dump the whole array into a set, the set's
 *   final size equals the number of DISTINCT values. If that count is smaller
 *   than the array length, at least one value collapsed on insertion -- i.e. a
 *   duplicate existed. The whole answer reduces to comparing two sizes.
 *
 *     distinct count == array length  -> no duplicates -> false
 *     distinct count <  array length  -> a duplicate   -> true
 *
 *   Why a set and not sorting? A hash set gives O(1) average membership, so we
 *   settle the question in one linear pass instead of ordering the data first.
 *
 * WALKTHROUGH (this code, line by line)
 *   unordered_set<int> s;                  // will hold the distinct values
 *   for i in 0..nums.size()-1:             // one pass over every element
 *       s.insert(nums[i]);                 // duplicates are dropped by the set
 *   if nums.size() == s.size(): false      // nothing was dropped => all unique
 *   else: true                             // set shrank => something repeated
 *
 *   Note: the if/else could be written `return nums.size() != s.size();`, but
 *   the explicit branch is equivalent and just as correct.
 *
 *   Dry run on nums = [1,2,3,1]:
 *     i=0 insert 1 -> s={1}          size 1
 *     i=1 insert 2 -> s={1,2}        size 2
 *     i=2 insert 3 -> s={1,2,3}      size 3
 *     i=3 insert 1 -> already in s   size 3 (no growth <- the duplicate)
 *     nums.size()=4, s.size()=3 -> 4 != 3 -> return true  ✓
 *
 *   Dry run on nums = [5,9] :
 *     s ends {5,9}, size 2; nums.size()=2 -> equal -> return false  ✓
 *
 * COMPLEXITY
 *   Time : O(n) average -- one pass, each insert is expected O(1). Worst case
 *          O(n^2) only under pathological hash collisions (not typical here).
 *   Space: O(n) -- in the all-distinct case the set holds every element.
 *
 * EDGE CASES
 *   - Empty array: loop runs 0 times, both sizes are 0, 0==0 -> false. Correct
 *     (an empty array has no duplicates).
 *   - Single element: sizes both 1 -> false. Correct.
 *   - All identical, e.g. [7,7,7]: set ends {7} size 1 vs length 3 -> true.
 *   - Negative values / full int range: unordered_set<int> handles them fine.
 *   - `i` is a signed int compared against nums.size() (size_t/unsigned). For
 *     LeetCode's constraints (n <= 1e5) this never overflows, but it is a
 *     signed/unsigned comparison and would warn under -Wall; using size_t i
 *     would be cleaner.
 *
 * BETTER / OPTIMAL APPROACH
 *   The size-comparison version always scans the ENTIRE array even when the
 *   duplicate sits at index 1. Time and space are already optimal in Big-O,
 *   but you can short-circuit: check the insert result and bail the instant a
 *   collision happens. This avoids building the rest of the set on average.
 *
 *     bool containsDuplicate(vector<int>& nums) {
 *         unordered_set<int> s;
 *         for (int x : nums)
 *             if (!s.insert(x).second)   // .second is false when x already present
 *                 return true;
 *         return false;
 *     }
 *
 *   (Same O(n)/O(n) bounds; just returns earlier and needs no size compare.)
 *   If O(1) extra space matters more than speed, sort in place and scan for
 *   adjacent equals -- O(n log n) time, O(1) auxiliary space.
 * ==========================================================================*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        if(nums.size() == s.size()){
            return false;
        }
        else{
            return true;
        }
    }
};
