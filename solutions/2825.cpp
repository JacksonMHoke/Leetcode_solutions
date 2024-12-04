// 2825. Make String a Subsequence Using Cyclic Increments
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j=0;
        for (int i=0; i<str1.length() && j<str2.length(); ++i) {
            if (str2[j]==str1[i] || str2[j]==(str1[i]-'a'+1)%('z'-'a'+1)+'a')
                j++;
        }
        return j>=str2.length();
    }
};