/*
 * ============================================================================
 *  LeetCode 500 - Keyboard Row                                    [Easy]
 * ============================================================================
 *  @platform   LeetCode
 *  @id         500
 *  @title      Keyboard Row
 *  @difficulty Easy
 *  @topics     Array, Hash Table, String
 *  @pattern    Row Membership Flag Elimination
 *  @url        https://leetcode.com/problems/keyboard-row/
 *  @solved     2026-06-28
 * ----------------------------------------------------------------------------
 *
 *  PROBLEM
 *  -------
 *  An American keyboard has three letter rows:
 *      row1: q w e r t y u i o p
 *      row2: a s d f g h j k l
 *      row3: z x c v b n m
 *  Given a list of words, return only those words that can be typed using
 *  letters from ONE row alone. Matching is case-insensitive.
 *
 *      Input : ["Hello","Alaska","Dad","Peace"]
 *      Output: ["Alaska","Dad"]
 *      ("Alaska" is all row2 letters; "Dad" is all row2 letters. "Hello"
 *       and "Peace" mix rows, so they are dropped.)
 *
 *  INTUITION
 *  ---------
 *  A word belongs to a row iff EVERY one of its characters lives in that row.
 *  Rather than decide which row a word "should" be in, keep three optimistic
 *  hypotheses at once: "this word is entirely in row1 / row2 / row3." Scan the
 *  characters; the moment a character is missing from a row, that row's
 *  hypothesis is disproven and its flag is switched off permanently. If any
 *  flag survives the whole word, the word is typeable on one row.
 *  This works because the three flags are independent AND-tests, and a single
 *  contradicting character is enough to eliminate a row forever.
 *
 *  WALKTHROUGH (this code)
 *  -----------------------
 *  - row1/row2/row3 are literal alphabets holding BOTH cases of each letter,
 *    so `find(c)` handles case-insensitivity without any tolower() call.
 *  - For each word, first/second/third start as true (all rows still possible).
 *  - The inner loop tests every char c against all three rows:
 *        row.find(c) == string::npos  means c is NOT in that row -> flag = false.
 *    Note the loop never breaks early even after all flags die; it always scans
 *    the full word. Harmless for correctness, mild wasted work (see COMPLEXITY).
 *  - After the word, `first || second || third` asks "did any row survive?";
 *    if so, the word is pushed to `ans`.
 *
 *  DRY RUN on "Hello" then "Alaska":
 *    "Hello": flags = {1,1,1}
 *        'H' -> not in row1 -> first=false; not in row3 -> third=false; in row2.
 *        'e' -> not in row2 -> second=false.   Now {0,0,0}.
 *        'l','l','o' -> all flags already false, no change.
 *        first||second||third = false  -> "Hello" skipped.
 *    "Alaska": flags = {1,1,1}
 *        'A' -> not in row1 (first=false), not in row3 (third=false), in row2.
 *        'l','a','s','k','a' -> all present in row2 -> second stays true.
 *        second = true -> "Alaska" pushed.
 *    Final ans = ["Alaska", ...] (and "Dad" by the same logic).
 *
 *  COMPLEXITY
 *  ----------
 *  Time : O(N * L) where N = number of words, L = average word length.
 *         Each `find` scans a fixed-size alphabet (<= 20 chars), a constant
 *         factor, so total work is proportional to the total characters read.
 *  Space: O(1) auxiliary (three fixed strings + three bools); output vector
 *         excluded, as is standard.
 *
 *  EDGE CASES
 *  ----------
 *  - Empty word "": inner loop runs zero times, all three flags remain true,
 *    so "" is (correctly, per constraints) considered typeable and pushed.
 *  - Single-character word: always typeable; exactly one flag survives.
 *  - Mixed case within a row (e.g. "aA"): handled, since each row string lists
 *    both cases; no explicit case folding needed.
 *  - Non-letter input: constraints guarantee only English letters, so a char
 *    absent from all three rows would just drop the word (still safe).
 *
 *  OPTIONAL IMPROVEMENT (not required; current code is already linear)
 *  ------------------------------------------------------------------
 *  Each `find` re-scans an alphabet. A precomputed char->row map makes every
 *  lookup a true O(1) array index and removes the triple scan per character:
 *
 *      int row[128];                         // row id for each letter
 *      string R[3] = {"qwertyuiop","asdfghjkl","zxcvbnm"};
 *      for (int r = 0; r < 3; ++r)
 *          for (char c : R[r]) { row[c] = r; row[toupper(c)] = r; }
 *
 *      for (auto& w : words) {
 *          int base = row[(int)w[0]];
 *          bool ok = true;
 *          for (char c : w) if (row[(int)c] != base) { ok = false; break; }
 *          if (ok) ans.push_back(w);         // note the early break
 *      }
 *
 *  Same O(total chars) bound, but a smaller constant and an early exit.
 * ============================================================================
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
