/*
 * Platform: LeetCode
 * Submission: 2053842801
 * Problem: Keyboard Row
 * Verdict: Accepted
 * Submitted: 2026-07-02
 * Recorded in repository: 2026-09-24
 * URL: https://leetcode.com/problems/keyboard-row/
 *  */

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