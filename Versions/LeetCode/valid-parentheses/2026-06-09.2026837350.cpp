/*
 * Platform: LeetCode
 * Submission: 2026837350
 * Problem: Valid Parentheses
 * Verdict: Accepted
 * Submitted: 2026-06-09
 * Recorded in repository: 2026-09-24
 * Variant: Optimized (inferred from submission order)
 * URL: https://leetcode.com/problems/valid-parentheses/
 *  */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mp = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        }; 
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }
            else if(c == ')' || c == ']' || c == '}'){
                if(st.empty() == true){
                    return false;
                }
                else if(c == mp[st.top()]){
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