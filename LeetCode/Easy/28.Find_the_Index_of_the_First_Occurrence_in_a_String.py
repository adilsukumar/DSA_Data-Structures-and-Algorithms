"""
─────────────────────────────────────────────────────────────────────────────
 LeetCode 28 · Find the Index of the First Occurrence in a String       Easy
─────────────────────────────────────────────────────────────────────────────
 @platform   LeetCode
 @id         28
 @title      Find the Index of the First Occurrence in a String
 @difficulty Easy
 @topics     String, Two Pointers, String Matching
 @pattern    Sliding Window / Naive Substring Search
 @url        https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
─────────────────────────────────────────────────────────────────────────────

 PROBLEM
 -------
 Return the index of the first occurrence of `needle` in `haystack`, or -1 if
 it does not occur. (This is the classic C `strstr` / Python `str.find`.)

     haystack = "sadbutsad", needle = "sad"  ->  0
     haystack = "leetcode",  needle = "leeto" -> -1

 INTUITION
 ---------
 The needle, if it appears at all, must start at some index of the haystack. So
 try them all: line the needle up at index 0, compare; slide to index 1, compare;
 and so on. The first alignment that matches wins, which automatically gives the
 FIRST occurrence rather than just any occurrence.

 The only detail requiring thought is where to stop sliding.

 WALKTHROUGH
 -----------
 n, m = len(haystack), len(needle)

 for i in range(n - m + 1):        # every valid starting position
     if haystack[i:i+m] == needle: # does the window starting at i match?
         return i                  # first match -> done
 return -1

 WHY `n - m + 1` IS THE RIGHT BOUND
 ----------------------------------
 The last position where the needle can still fit entirely inside the haystack
 is index n - m. Since range() is exclusive on the upper end, we pass n - m + 1
 to include it. Concretely, with n=5 ("sadxx") and m=3 ("sad"), valid starts are
 0, 1, 2 -- that is range(3) = range(5-3+1). Going any further would compare a
 window shorter than the needle, which can never match anyway (Python slicing
 clamps silently rather than erroring, so this would be a wasted comparison, not
 a crash) -- and this bound also makes the "needle longer than haystack" case
 fall out for free: n - m + 1 is <= 0, so range() is empty and we return -1.

 `haystack[i:i+m]` builds the m-character window starting at i, and `== needle`
 compares it. Python does that comparison in optimised C, which is why this
 short version runs fast in practice despite being the naive algorithm.

 Dry run on haystack = "sadbutsad", needle = "sad" (n=9, m=3, so i in 0..6):
     i=0: "sad" == "sad"  ->  return 0    ✔  (index 6 also matches, but 0 is first)

 Dry run on haystack = "leetcode", needle = "leeto" (n=8, m=5, i in 0..3):
     i=0: "leetc" != "leeto"
     i=1: "eetco" != "leeto"
     i=2: "etcod" != "leeto"
     i=3: "tcode" != "leeto"
     loop ends  ->  return -1    ✔

 COMPLEXITY
 ----------
 Time : O(n * m) worst case -- there are ~n alignments and each slice-compare
        costs up to m. The pathological input is haystack "aaaa...a" with needle
        "aaa...ab": every window matches for m-1 characters before failing on
        the last one. Note the slicing also COPIES m characters per iteration.
 Space: O(m) -- each slice allocates a temporary string of length m. Comparing
        character by character with an inner loop would make this O(1).

 EDGE CASES
 ----------
 - Empty needle -> m=0, range(n+1) starts at i=0, and "" == "" is True, so it
   returns 0. That matches the problem's expected behaviour.
 - needle longer than haystack -> empty range -> -1, as shown above.
 - needle == haystack -> single iteration, matches at 0.

 ⚠ THE REASON THIS PROBLEM EXISTS -- KMP, O(n + m)
 -------------------------------------------------
 Naive search is quadratic because after a partial match fails it throws away
 everything it just learned and restarts the needle from scratch. KMP
 (Knuth-Morris-Pratt) fixes exactly that.

 Precompute an LPS array over the needle, where lps[i] = the length of the
 longest proper prefix of needle[0..i] that is also a suffix of it. When a
 mismatch happens after matching j characters, those j characters are known
 text -- so instead of restarting at j=0, you jump to j = lps[j-1], the longest
 prefix already re-matched by the tail of what you read. The haystack pointer
 NEVER moves backwards, which is what buys the linear bound.

 KMP is the intended "real" answer and shows up often in interviews. Boyer-Moore
 and Rabin-Karp (rolling hash) are the other two standard approaches worth
 knowing. But be aware: on LeetCode the naive version passes comfortably here,
 because the constraints cap both strings at 10^4.

 IN REAL CODE
 ------------
 Outside an interview this is simply `haystack.find(needle)`, which returns the
 index or -1 -- identical contract, and implemented in C.
─────────────────────────────────────────────────────────────────────────────
"""

class Solution:
    def strStr(self, haystack, needle):

        n, m = len(haystack), len(needle)

        for i in range(n - m + 1):
            if haystack[i:i+m] == needle:
                return i

        return -1
