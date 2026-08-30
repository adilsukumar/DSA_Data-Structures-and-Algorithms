/*
 * LeetCode 20 - Valid Parentheses [Easy]
 *
 * @platform   LeetCode
 * @id         20
 * @title      Valid Parentheses
 * @difficulty Easy
 * @topics     Stack, String, Hash Table
 * @pattern    Stack Matching (LIFO)
 * @url        https://leetcode.com/problems/valid-parentheses/
 * @solved     2026-06-08
 *
 * Problem
 * Given a string of only ()[]{}, decide whether the brackets are valid.
 *
 * Approach
 * Push opening brackets onto a stack. Each closing bracket must match the most recent
 * opener, and the stack must be empty after the final character.
 *
 * Complexity
 * Time: O(n) -- each character is pushed at most once and popped at most once.
 * Space: O(n) -- worst case "((((((" pushes every character onto the stack.
 *
 * Notes
 * - Empty string "" -> loop never runs, st is empty -> true.
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char, char> mp = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };

        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else if(c == ')' || c == ']' || c == '}') {
                if(st.empty()) {
                    return false;
                }
                else if(c == mp[st.top()]) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
