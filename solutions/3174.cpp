// 3174. Clear Digits
class Solution {
public:
    string clearDigits(string s) {
        string rt;
        for (int i=0; i<s.length(); ++i) {
            if (s[i]>='0' && s[i]<='9' && !rt.empty())
                rt.pop_back();
            else
                rt+=s[i];
        }
        return rt;
    }
};