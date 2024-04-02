// 58. Length of Last Word
class Solution {
public:
    int lengthOfLastWord(string s) {
        int rt=0;
        int i=s.length()-1;
        while (s[i]==' ')
            --i;
        for (; i>=0; --i) {
            if (s[i]==' ')
                break;
            rt++;
        }
        return rt;
    }
};