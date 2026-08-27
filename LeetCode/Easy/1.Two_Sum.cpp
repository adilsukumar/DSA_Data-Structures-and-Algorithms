/*
 * ─────────────────────────────────────────────────────────────────────────────
 *  LeetCode 1 · Two Sum                                                   Easy
 * ─────────────────────────────────────────────────────────────────────────────
 *  @platform   LeetCode
 *  @id         1
 *  @title      Two Sum
 *  @difficulty Easy
 *  @topics     Array, Hash Table
 *  @pattern    Brute-Force Pair Scan
 *  @url        https://leetcode.com/problems/two-sum/
 *  @solved     2026-06-04
 * ─────────────────────────────────────────────────────────────────────────────
 *
 *  PROBLEM
 *  -------
 *  Given an array `nums` and an integer `target`, return the INDICES of the two
 *  numbers that add up to `target`. Exactly one valid answer exists, and you may
 *  not use the same element twice.
 *
 *      nums = [2,7,11,15], target = 9   ->  [0,1]   because nums[0]+nums[1] == 9
 *
 *  Note it asks for indices, not the values. That detail is what makes sorting
 *  a trap: sorting destroys the original positions.
 *
 *  INTUITION
 *  ---------
 *  The most direct reading of the problem is "try every pair". There are only
 *  n*(n-1)/2 pairs, so we can just look at all of them and stop at the first one
 *  that sums to the target. Since the problem guarantees exactly one answer, the
 *  first pair we find IS the answer -- no need to keep searching.
 *
 *  The only real thought here is: how do we enumerate each pair exactly once?
 *  If `i` walks the array and `j` always starts at `i + 1`, then j is always to
 *  the right of i. That gives two things for free:
 *      1. We never pair an element with itself  (j != i).
 *      2. We never check the same pair twice     ((0,1) yes, (1,0) never).
 *
 *  WALKTHROUGH
 *  -----------
 *  for(int i = 0; i < nums.size(); i++)          // left element of the pair
 *      for(int j = i + 1; j < nums.size(); j++)  // right element, always ahead
 *          if(nums[i] + nums[j] == target)
 *              return {i, j};                    // guaranteed unique -> done
 *
 *  Dry run on nums = [2,7,11,15], target = 9:
 *      i=0 (2): j=1 (7)  -> 2+7  = 9  == target -> return {0,1}   ✔
 *
 *  Dry run on nums = [3,2,4], target = 6:
 *      i=0 (3): j=1 (2)  -> 3+2  = 5  no
 *               j=2 (4)  -> 3+4  = 7  no
 *      i=1 (2): j=2 (4)  -> 2+4  = 6  == target -> return {1,2}   ✔
 *      (Notice it correctly skips {0,0} = 3+3 = 6, which would be reusing an
 *       element. That is exactly what `j = i + 1` protects against.)
 *
 *  `return {}` at the end returns an empty vector. It is unreachable given the
 *  problem's guarantee, but C++ requires every path to return a value.
 *
 *  COMPLEXITY
 *  ----------
 *  Time : O(n^2)  -- the inner loop runs n-1, then n-2, ... then 1 time.
 *  Space: O(1)    -- only the two loop counters; the output doesn't count.
 *
 *  EDGE CASES
 *  ----------
 *  - Duplicate values, e.g. [3,3] target 6 -> i=0, j=1 works fine.
 *  - Negative numbers work unchanged; nothing here assumes positivity.
 *  - n == 1 -> the inner loop never runs, falls through to `return {}`.
 *
 *  ⚠ BETTER APPROACH -- one-pass hash map, O(n)
 *  --------------------------------------------
 *  The brute force re-scans the right side of the array over and over. The trick
 *  is to flip the question: instead of asking "does some later element pair with
 *  me?", ask "did some EARLIER element need exactly me?".
 *
 *  For each nums[i], its required partner is `target - nums[i]`. If we remember
 *  every value we have already seen (value -> index) in a hash map, we can check
 *  for that partner in O(1) instead of scanning:
 *
 *      vector<int> twoSum(vector<int>& nums, int target) {
 *          unordered_map<int, int> seen;              // value -> its index
 *          for (int i = 0; i < nums.size(); i++) {
 *              int need = target - nums[i];
 *              if (seen.count(need))                  // partner already passed by
 *                  return {seen[need], i};
 *              seen[nums[i]] = i;                     // record AFTER checking
 *          }
 *          return {};
 *      }
 *
 *  Time O(n), Space O(n). Recording *after* the lookup is what stops an element
 *  from matching itself (e.g. target 6 with a single 3 in the array).
 *
 *  This trade -- spend memory to avoid a nested loop -- is the single most
 *  reused idea in array interview questions. Worth internalising here.
 * ─────────────────────────────────────────────────────────────────────────────
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};
