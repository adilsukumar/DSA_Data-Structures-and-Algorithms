/*
 * LeetCode 125 - Valid Palindrome [Easy]
 *
 * @platform   LeetCode
 * @id         125
 * @title      Valid Palindrome
 * @difficulty Easy
 * @topics     Two Pointers, String
 * @pattern    Converging Two Pointers
 * @url        https://leetcode.com/problems/valid-palindrome/
 * @solved     2026-06-22
 *
 * Problem
 * A string is a valid palindrome if, after (a) dropping every character that is not a
 * letter or digit and (b) lowercasing the rest, it reads the same forwards and backwards.
 *
 * Approach
 * You don't need to build the cleaned string at all. A palindrome is defined by symmetry
 * around the center, so compare the string from both ends inward.
 *
 * Complexity
 * Time: O(n): each pointer moves strictly inward and they never overlap work, so every
 * index is visited at most once across all loops.
 * Space: O(1): only two integer indices; the input is inspected in place.
 *
 * Notes
 * - Empty string: outer loop never runs (see the length()-1 note) -> true.
 */

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            while(left < right && !isalnum(s[left])){
                left++;
            }
            while(left < right && !isalnum(s[right])){
                right--;
            }
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;

    }
};
