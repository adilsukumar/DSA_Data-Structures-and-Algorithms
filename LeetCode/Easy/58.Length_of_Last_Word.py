"""
─────────────────────────────────────────────────────────────────────────────
 LeetCode 58 · Length of Last Word                                      Easy
─────────────────────────────────────────────────────────────────────────────
 @platform   LeetCode
 @id         58
 @title      Length of Last Word
 @difficulty Easy
 @topics     String
 @pattern    Tokenise and Take Last
 @url        https://leetcode.com/problems/length-of-last-word/
 @solved     2026-06-14
─────────────────────────────────────────────────────────────────────────────

 PROBLEM
 -------
 Given a string of words separated by spaces, return the length of the LAST
 word. A word is a maximal run of non-space characters.

     "Hello World"              ->  5
     "   fly me   to   the moon "  ->  4   ("moon", despite the trailing space)
     "luffy is still joyboy"    ->  6

 The trailing-space case in example 2 is the trap the problem is built around:
 a naive "count backwards from the end" fails on it unless you first skip the
 trailing spaces.

 INTUITION
 ---------
 Rather than handle the whitespace by hand, hand the job to `split()`. Python's
 `str.split()` called with NO arguments does something specifically useful here:
 it splits on ANY run of whitespace and discards empty results. So all the messy
 cases -- leading spaces, trailing spaces, multiple spaces in a row -- are
 normalised away in one call. What comes back is a clean list of words, and the
 answer is just the length of the last one.

     "   fly me   to   the moon ".split()  ->  ['fly','me','to','the','moon']

 Note this is NOT true of `split(" ")`, which splits on each single space and
 keeps the empties: `"a  b ".split(" ")` gives `['a','','b','']`, and the last
 element is the empty string. Relying on the argument-less form is what makes
 this correct.

 WALKTHROUGH
 -----------
 a = s.split()      # list of words, whitespace fully normalised
 b = list(a)        # copy of that list  (see NOTE -- this line does nothing)
 c = b[-1]          # [-1] is Python's negative index for "the last element"
 count = 0
 for i in c:        # walk the characters of the last word...
     count += 1     # ...counting them
 return count

 Dry run on "   fly me   to   the moon ":
     a = ['fly','me','to','the','moon']
     c = 'moon'
     the loop counts m,o,o,n  ->  count = 4    ✔

 COMPLEXITY
 ----------
 Time : O(n)  -- split() scans the whole string once; the counting loop then
                 walks only the last word, which is at most n.
 Space: O(n)  -- split() materialises every word into a new list, and `list(a)`
                 allocates a second list on top of that.

 EDGE CASES
 ----------
 - Trailing spaces "a "      -> split() drops them, c = 'a', returns 1. ✔
 - Multiple inner spaces     -> collapsed by split(). ✔
 - Single word "day"         -> ['day'], returns 3. ✔
 - A string of ONLY spaces "   " would make split() return [] and `b[-1]` raise
   IndexError. LeetCode's constraints guarantee at least one non-space
   character, so it cannot happen here -- but it is the one input that would
   break this, and worth naming if asked.

 NOTES ON THE CODE
 -----------------
 1. `b = list(a)` makes a shallow copy of `a` that is then used exactly once and
    never mutated. It can be deleted; `c = a[-1]` works identically.

 2. The counting loop is re-implementing `len()`. Python strings know their own
    length in O(1) -- there is no need to walk them:

        return len(s.split()[-1])

    That one line is the whole solution, and it is what an interviewer would
    expect to see. Reaching for a manual counter when a built-in exists is a
    habit worth dropping early; it costs time under pressure and adds places to
    make an off-by-one error.

 ⚠ BETTER APPROACH -- O(1) space, scan from the right
 ----------------------------------------------------
 split() builds a list of EVERY word just to look at one of them. If the string
 is huge and you only need the tail, walk backwards instead:

     def lengthOfLastWord(self, s: str) -> int:
         i = len(s) - 1
         while i >= 0 and s[i] == ' ':   # step 1: skip trailing spaces
             i -= 1
         length = 0
         while i >= 0 and s[i] != ' ':   # step 2: count the word's characters
             length += 1
             i -= 1
         return length

 Two loops in a deliberate order, and the order is the whole point -- skipping
 the trailing spaces BEFORE counting is what handles "moon " correctly. This is
 O(1) extra space, and it touches only the trailing spaces plus the last word
 rather than the entire string.
─────────────────────────────────────────────────────────────────────────────
"""

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        a = s.split()
        b = list(a)
        c = b[-1]
        count = 0
        for i in c:
            count += 1
        return count
            
        
