/*
 * Platform: LeetCode
 * Submission: 2026827027
 * Problem: Valid Parentheses
 * Verdict: Compile Error
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
                if(st.empty() == true){
                    return false;
                }
                else if(st.top() == '('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(c == ']'){
                if(st.empty() == true){
                    return false;
                }
                else if(st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(c == '}'){
                if(st.empty() == true){
                    return false;
                }
                else if(st.top() == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
    if(st.empty() == true){
        return true;
    }
    }
};