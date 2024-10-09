// 921. Minimum Add to Make Parentheses Valid
class Solution {
public:
    int minAddToMakeValid(string s) {
        int parens=0, inserts=0;
        for (int i=0; i<s.length(); ++i) {
            parens+=(s[i]=='(')-(s[i]==')');
            if (parens<0) {
                inserts-=parens;
                parens=0;
            }
        }
        return inserts+parens;
    }
};