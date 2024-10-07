// 2696. Minimum String Length After Removing Substrings
class Solution {
public:
    int minLength(string s) {
        stack<char> prev;
        for (int i=0; i<s.length(); ++i) {
            if (!prev.empty() && (s[i]=='B' && prev.top()=='A' || s[i]=='D' && prev.top()=='C'))
                prev.pop();
            else
                prev.push(s[i]);
        }
        return prev.size();
    }
};