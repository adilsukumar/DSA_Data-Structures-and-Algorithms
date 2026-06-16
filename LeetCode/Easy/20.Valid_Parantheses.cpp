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
