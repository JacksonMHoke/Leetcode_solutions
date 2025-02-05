// 1790. Check if One String Swap Can Make Strings Equal
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diffs=0, diff1=-1, diff2=-1;
        for (int i=0; i<s1.length(); ++i) {
            if (s1[i]!=s2[i]) {
                diffs++;
                diff2=exchange(diff1, i);
            }
        }
        return diffs==0 || (diffs==2 && s1[diff1]==s2[diff2] && s1[diff2]==s2[diff1]);
    }
};