// 1190. Reverse Substrings Between Each Pair of Parentheses
// HEAVY INSPIRATION FROM LEE
// Genius solution by him
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> pIndexes;
        vector<int> pairs(s.length());
        for (int i=0; i<s.length(); ++i) {
            if (s[i]=='(')
                pIndexes.push(i);
            if (s[i]==')') {
                pairs[i]=pIndexes.top();
                pairs[pIndexes.top()]=i;
                pIndexes.pop();
            }
        }

        int i=0, dir=1;
        string rt="";
        for (; i>=0 && i<s.length(); i+=dir) {
            if (s[i]=='(' || s[i]==')') {
                dir=-dir;
                i=pairs[i];
            } else {
                rt+=s[i];
            }
        }
        return rt;
    }
};

// (ed(et(oc))el)
// (ed(etco)el)
// (edocteel)
// leetcode