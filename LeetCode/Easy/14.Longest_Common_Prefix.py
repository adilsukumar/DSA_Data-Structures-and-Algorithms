"""
─────────────────────────────────────────────────────────────────────────────
 LeetCode 14 · Longest Common Prefix                                    Easy
─────────────────────────────────────────────────────────────────────────────
 @platform   LeetCode
 @id         14
 @title      Longest Common Prefix
 @difficulty Easy
 @topics     String, Trie
 @pattern    Vertical Scanning
 @url        https://leetcode.com/problems/longest-common-prefix/
 @solved     2026-06-07
─────────────────────────────────────────────────────────────────────────────

 PROBLEM
 -------
 Find the longest string that is a prefix of EVERY string in the array. If
 there is no common prefix, return "".

     ["flower","flow","flight"]  ->  "fl"
     ["dog","racecar","car"]     ->  ""    (they differ at the very first char)

 INTUITION
 ---------
 There are two natural ways to attack this:

   Horizontal scanning -- take the first word as a candidate answer, then walk
     the list shrinking that candidate until it fits every word.
   Vertical scanning   -- compare the words COLUMN by column: check every word's
     character 0, then every word's character 1, and so on. The moment one
     column disagrees, the prefix ends right there.

 This solution takes the vertical approach, and it has a nice property: it stops
 the instant it finds a mismatch, so it never reads further into the strings
 than it has to. On ["a...","b..."] with very long strings it does 2 character
 comparisons total, regardless of how long those strings are.

 WALKTHROUGH
 -----------
 ans = ""                          # the prefix confirmed so far

 for i in range(len(strs[0])):     # i = the COLUMN index we are checking.
                                   # strs[0] bounds the loop because the answer
                                   # can never be longer than the first word.

     for j in range(len(strs)):    # j = which word we are looking at

         if i >= len(strs[j]):     # word j has run out of characters. It is
             return ans            # shorter than the prefix we were building,
                                   # so the prefix stops here. Without this
                                   # guard, strs[j][i] would raise IndexError.

         if strs[j][i] != strs[0][i]:   # word j disagrees with the reference
             return ans                 # word at this column -> prefix ends

     ans += strs[0][i]             # every word agreed on this column, so the
                                   # character is genuinely part of the prefix

 return ans                        # ran out of columns: strs[0] is itself the
                                   # common prefix (e.g. ["ab","abc","abcd"])

 Dry run on ["flower","flow","flight"]:
     i=0 ('f'): "flower"✓ "flow"✓ "flight"✓          -> ans = "f"
     i=1 ('l'): "flower"✓ "flow"✓ "flight"✓          -> ans = "fl"
     i=2 ('o'): "flower"✓ "flow"✓ "flight" has 'i'   -> mismatch, return "fl" ✔

 Dry run on ["flow","flower"] (the shorter-word path):
     i=0,1,2,3 all agree                             -> ans = "flow"
     loop ends because len(strs[0]) == 4             -> return "flow" ✔

 Dry run on ["flower","flow"] (shorter word is NOT first):
     i=0..3 agree                                    -> ans = "flow"
     i=4: j=1, i(4) >= len("flow")(4) is True        -> return "flow" ✔
     This is the case the `i >= len(strs[j])` guard exists for.

 COMPLEXITY
 ----------
 Time : O(S) worst case, where S is the total number of characters across all
        strings. In practice it is O(m * n) with m = length of the answer + 1
        and n = number of words, since it stops at the first mismatched column.
 Space: O(m) for the `ans` string being accumulated. If you returned a slice
        instead, it would be O(1) extra.

 EDGE CASES
 ----------
 - No common prefix at all -> mismatch at i=0 -> returns "" correctly.
 - An empty string in the list, e.g. ["", "abc"] -> at i=0 the guard
   `0 >= len("")` fires immediately -> returns "". Correct.
 - A single word ["abc"] -> the inner loop only ever compares strs[0] to itself,
   so every column passes -> returns "abc". Correct.
 - LeetCode guarantees at least one string, so `strs[0]` is safe. If it did not,
   you would need an `if not strs: return ""` guard first.

 NOTE ON STYLE
 -------------
 `ans += strs[0][i]` builds the string one character at a time. In CPython this
 is fine at these sizes, but the idiomatic finish is to track only the index and
 slice once at the end -- `return strs[0][:i]` -- which avoids repeated string
 allocation and reads more clearly.

 WHY "Trie" IS A LISTED TOPIC
 ----------------------------
 LeetCode tags this with Trie because if you had to answer this repeatedly for
 many different subsets of the same word list, you would insert all words into a
 trie once and then walk down from the root while each node has exactly one
 child and is not a word-end. That is overkill for a single query, but it is the
 reason the tag is there.
─────────────────────────────────────────────────────────────────────────────
"""

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans = ""

        for i in range(len(strs[0])):
            for j in range(len(strs)):
                if i >= len(strs[j]):
                    return ans

                if strs[j][i] != strs[0][i]:
                    return ans

            ans += strs[0][i]

        return ans
