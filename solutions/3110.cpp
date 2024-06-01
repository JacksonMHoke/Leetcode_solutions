// 3110. Score of a String
class Solution {
public:
    int scoreOfString(string s) {
        int rt=0;
        for (int i=0; i<s.length()-1;++i)
            rt+=abs(s[i]-s[i+1]);
        return rt;
    }
};
