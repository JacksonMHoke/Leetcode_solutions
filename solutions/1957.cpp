// 1957. Delete Characters to Make Fancy String
class Solution {
public:
    string makeFancyString(string s) {
        int cnt=1;
        string rt=string(1, s[0]);
        for (int i=1; i<s.length(); ++i) {
            if (s[i-1]==s[i])
                cnt++;
            else
                cnt=1;
            
            if (cnt<3)
                rt+=s[i];
        }
        return rt;
    }
};