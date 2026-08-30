/*
 * LeetCode 500 - Keyboard Row [Easy]
 *
 * @platform   LeetCode
 * @id         500
 * @title      Keyboard Row
 * @difficulty Easy
 * @topics     Array, Hash Table, String
 * @pattern    Row Membership Flag Elimination
 * @url        https://leetcode.com/problems/keyboard-row/
 * @solved     2026-06-28
 *
 * Problem
 * An American keyboard has three letter rows: row1: q w e r t y u i o p row2: a s d f g h
 * j k l row3: z x c v b n m Given a list of words, return only those words that can be
 * typed using letters from ONE row alone.
 *
 * Approach
 * A word belongs to a row only if every character belongs to that row. Rather than
 * decide which row a word "should" be in, keep three optimistic hypotheses at once: "this
 * word is entirely in row1 / row2 / row3." Scan the characters; the moment a character is
 * missing from a row, that row's hypothesis is disproven.
 *
 * Complexity
 * Time: O(N * L) where N = number of words, L = average word length.
 * Space: O(1) auxiliary (three fixed strings + three bools); output vector excluded, as is
 * standard.
 *
 * Notes
 * - Empty word "": inner loop runs zero times, all three flags remain true, so "" is
 *   (correctly, per constraints) considered typeable and pushed.
 */

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;

        string row1 = "qwertyuiopQWERTYUIOP";
        string row2 = "asdfghjklASDFGHJKL";
        string row3 = "zxcvbnmZXCVBNM";

        for (int i = 0; i < words.size(); i++) {

            bool first = true;
            bool second = true;
            bool third = true;

            for (char c : words[i]) {
                if (row1.find(c) == string::npos)
                    first = false;
                if (row2.find(c) == string::npos)
                    second = false;
                if (row3.find(c) == string::npos)
                    third = false;
            }

            if (first || second || third)
                ans.push_back(words[i]);
        }

        return ans;
    }
};
