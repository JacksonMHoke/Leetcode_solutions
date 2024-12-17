// 2182. Construct String With Repeat Limit
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freqs(26);
        for (int i=0; i<s.length(); ++i)
            freqs[s[i]-'a']++;
        int i=25,j=25;
        string rt;
        while (i>=0 || j>=0) {
            while (i>=0 && freqs[i]<=0)
                i--;
            j=i-1;
            while (j>=0 && freqs[j]<=0)
                j--;
            if (i<0)
                return rt;
            rt+=string(min(repeatLimit, freqs[i]), i+'a');
            freqs[i]-=min(repeatLimit, freqs[i]);
            if (j<0)
                return rt;
            if (freqs[i]>0) {
                rt+=(char)j+'a';
                freqs[j]--;
            }
        }
        return rt;
    }
};