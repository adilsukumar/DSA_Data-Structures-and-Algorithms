"""
LeetCode 28 - Find the Index of the First Occurrence in a String [Easy]

@platform   LeetCode
@id         28
@title      Find the Index of the First Occurrence in a String
@difficulty Easy
@topics     String, Two Pointers, String Matching
@pattern    Sliding Window / Naive Substring Search
@url        https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
@solved     2026-06-12

Problem
Return the index of the first occurrence of `needle` in `haystack`, or -1 if it does not
occur.

Approach
The needle, if it appears at all, must start at some index of the haystack. So try them
all: line the needle up at index 0, compare; slide to index 1, compare; and so on.

Complexity
Time: O(n * m) worst case -- there are ~n alignments and each slice-compare costs up to
m.
Space: O(m) -- each slice allocates a temporary string of length m.

Notes
- Empty needle -> m=0, range(n+1) starts at i=0, and "" == "" is True, so it returns 0.
"""

class Solution:
    def strStr(self, haystack, needle):

        n, m = len(haystack), len(needle)

        for i in range(n - m + 1):
            if haystack[i:i+m] == needle:
                return i

        return -1
