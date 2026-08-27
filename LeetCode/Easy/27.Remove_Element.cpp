/*
 * ─────────────────────────────────────────────────────────────────────────────
 *  LeetCode 27 · Remove Element                                           Easy
 * ─────────────────────────────────────────────────────────────────────────────
 *  @platform   LeetCode
 *  @id         27
 *  @title      Remove Element
 *  @difficulty Easy
 *  @topics     Array, Two Pointers
 *  @pattern    Fast / Slow Read-Write Pointers
 *  @url        https://leetcode.com/problems/remove-element/
 *  @solved     2026-06-11
 * ─────────────────────────────────────────────────────────────────────────────
 *
 *  PROBLEM
 *  -------
 *  Remove all occurrences of `val` from `nums` IN PLACE and return k, the count
 *  of remaining elements. The first k slots must contain the survivors; the
 *  order of those survivors may be anything, and anything past index k is
 *  ignored by the judge.
 *
 *      nums = [3,2,2,3], val = 3  ->  k = 2, nums begins [2,2,_,_]
 *
 *  INTUITION
 *  ---------
 *  "Removing" from an array in place is really COMPACTION: you cannot delete a
 *  slot, so instead you copy everything you want to keep to the front, in order,
 *  and report how far the keepers reach.
 *
 *  That needs two independent positions, which is why one loop counter is not
 *  enough:
 *      - where you are READING from  (advances every single step)
 *      - where you are WRITING to    (advances only when you keep something)
 *
 *  Those are the fast and slow pointers. Their gap is exactly the number of
 *  elements deleted so far.
 *
 *  WALKTHROUGH
 *  -----------
 *  int k = 0;                                // WRITE pointer / survivor count
 *
 *  for(int i = 0; i < nums.size(); i++){     // READ pointer, sees everything
 *      if(nums[i] != val){                   // is this element a keeper?
 *          nums[k] = nums[i];                // move it to the front region
 *          k++;                              // the keep-region grew by one
 *      }
 *      // if nums[i] == val we simply do nothing: i moves on, k does not, and
 *      // the value gets overwritten by a later keeper (or left as ignored junk)
 *  }
 *  return k;
 *
 *  WHY THE WRITE CAN NEVER CORRUPT THE READ
 *  ----------------------------------------
 *  This is the part worth being able to justify out loud. k starts equal to i
 *  and only ever advances when i does, so k <= i always holds. Therefore
 *  `nums[k] = nums[i]` either writes onto a slot i has already passed, or writes
 *  a slot onto itself. It can never overwrite an element that has not been read
 *  yet. That invariant is what makes in-place compaction safe.
 *
 *  Dry run on nums = [0,1,2,2,3,0,4,2], val = 2:
 *      i=0 (0) keep -> nums[0]=0, k=1
 *      i=1 (1) keep -> nums[1]=1, k=2
 *      i=2 (2) skip           k=2      <- gap opens between i and k
 *      i=3 (2) skip           k=2
 *      i=4 (3) keep -> nums[2]=3, k=3
 *      i=5 (0) keep -> nums[3]=0, k=4
 *      i=6 (4) keep -> nums[4]=4, k=5
 *      i=7 (2) skip           k=5
 *      return 5, nums begins [0,1,3,0,4]    ✔
 *
 *  COMPLEXITY
 *  ----------
 *  Time : O(n)  -- one pass, one comparison per element.
 *  Space: O(1)  -- two integers, no allocation.
 *
 *  EDGE CASES
 *  ----------
 *  - Empty array -> loop never runs, returns 0.
 *  - No element equals val -> k ends at n, every write is a self-assignment.
 *  - Every element equals val -> k stays 0, returns 0.
 *
 *  RELATED VARIANT -- when removals are rare
 *  -----------------------------------------
 *  If order does NOT matter (which this problem allows) and you expect very few
 *  matches, you can instead swap each matched element with the last element and
 *  shrink the boundary:
 *
 *      int removeElement(vector<int>& nums, int val) {
 *          int n = nums.size(), i = 0;
 *          while (i < n) {
 *              if (nums[i] == val) nums[i] = nums[--n];  // pull the tail in
 *              else i++;                                 // note: do NOT i++ here
 *          }
 *          return n;
 *      }
 *
 *  Same O(n) worst case, but it performs only as many writes as there are
 *  removals, instead of one write per surviving element. Not `i++`-ing after a
 *  swap is essential -- the value just pulled in from the tail has not been
 *  checked yet.
 *
 *  This is the same two-pointer skeleton as problem 26 (Remove Duplicates); only
 *  the keep-condition changes. Recognising that two problems share a skeleton is
 *  most of what pattern practice is for.
 * ─────────────────────────────────────────────────────────────────────────────
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
