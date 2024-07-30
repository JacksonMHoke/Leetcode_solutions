// 1653. Minimum Deletions to Make String Balanced
class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> prefixBs(s.length());
        prefixBs[0]=s[0]=='b';
        for (int i=1; i<s.length(); ++i)
            prefixBs[i]=prefixBs[i-1]+(s[i]=='b');
        int numAs=0;
        int rt=INT_MAX;
        for (int i=s.length()-1; i>=0; --i) {
            rt=min(rt, numAs+prefixBs[i]);
            numAs+=s[i]=='a';
        }

        return (numAs==0) ? 0 : min(rt, numAs);
    }
};