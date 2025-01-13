// 3223. Minimum Length of String After Operations
class Solution {
public:
    int minimumLength(string s) {
        vector<int> freqs(26);
        for (int i=0; i<s.length(); ++i)
            freqs[s[i]-'a']++;
        int rt=0;
        for (int i=0; i<26; ++i) {
            if (freqs[i]%2==1)
                rt++;
            if (freqs[i]%2==0 && freqs[i]>0)
                rt+=2;
        }
        return rt;
    }
};