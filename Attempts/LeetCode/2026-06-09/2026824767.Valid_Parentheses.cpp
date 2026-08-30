/*
 * Platform: LeetCode
 * Submission: 2026824767
 * Problem: Valid Parentheses
 * Verdict: Wrong Answer
 * Date: 2026-06-09
 * URL: https://leetcode.com/problems/valid-parentheses/
 *  */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }
            else if(c == ')'){
                if(st.top() == '('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(c == ']'){
                if(st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(c == '}'){
                if(st.top() == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if (st.empty() == true){
                return false;
            }
        }
    return true;
    }
};