/*
 * Platform: LeetCode
 * Submission: 2026828003
 * Problem: Valid Parentheses
 * Verdict: Accepted
 * Submitted: 2026-06-09
 * Recorded in repository: 2026-09-24
 * Variant: Brute Force (inferred from submission order)
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
    return st.empty();
    }
};