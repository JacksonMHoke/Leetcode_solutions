// 1249. Minimum Remove to Make Valid Parentheses
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> skip;

        for (int i=0; i<s.length(); ++i) {
            if (s[i]=='(')
                st.push(i);
            if (s[i]==')') {
                if (st.empty())
                    skip.insert(i);
                else
                    st.pop();
            }
        }
        while (!st.empty()) {
            skip.insert(st.top());
            st.pop();
        }
        string rt="";
        for (int i=0; i<s.length(); ++i) {
            if (skip.find(i)==skip.end())
                rt+=s[i];
        }
        return rt;
    }
};