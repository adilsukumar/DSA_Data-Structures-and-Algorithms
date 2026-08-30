"""
LeetCode 58 - Length of Last Word [Easy]

@platform   LeetCode
@id         58
@title      Length of Last Word
@difficulty Easy
@topics     String
@pattern    Tokenise and Take Last
@url        https://leetcode.com/problems/length-of-last-word/
@solved     2026-06-14

Problem
Given a string of words separated by spaces, return the length of the LAST word.

Approach
Rather than handle the whitespace by hand, hand the job to `split()`. Python's
`str.split()` called with NO arguments does something specifically useful here: it
splits on ANY run of whitespace and discards empty results.

Complexity
Time: O(n) -- split() scans the whole string once; the counting loop then walks only the
last word, which is at most n.
Space: O(n) -- split() materialises every word into a new list, and `list(a)` allocates
a second list on top of that.

Notes
- Trailing spaces "a " -> split() drops them, c = 'a', returns 1.
- Scan backward after skipping trailing spaces to avoid building a list of every word.
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
            
        
