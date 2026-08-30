"""
LeetCode 14 - Longest Common Prefix [Easy]

@platform   LeetCode
@id         14
@title      Longest Common Prefix
@difficulty Easy
@topics     String, Trie
@pattern    Vertical Scanning
@url        https://leetcode.com/problems/longest-common-prefix/
@solved     2026-06-07

Problem
Find the longest string that is a prefix of every string in the array.

Approach
Use the first string as a reference and compare each character position across every
string. Stop at the first mismatch or when any string ends.

Complexity
Time: O(S) worst case, where S is the total number of characters across all strings.
Space: O(m) for the `ans` string being accumulated.

Notes
- No common prefix at all -> mismatch at i=0 -> returns "" correctly.
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
