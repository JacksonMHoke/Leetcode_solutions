// 1614. Maximum Nesting Depth of the Parentheses
class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int max_depth=0;
        for (int i=0; i<s.length(); ++i) {
            if (s[i]=='(')
                max_depth=max(max_depth, ++depth);
            if (s[i]==')')
                depth--;
        }
        return max_depth;
    }
};