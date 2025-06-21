// 3085. Minimum Deletions to Make String K-Special
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freqs(26);
        for (auto c : word)
            freqs[c-'a']++;
        sort(freqs.begin(), freqs.end());
        int r=0, rt=INT_MAX, sm=0;
        for (int i=0; i<26; ++i) {
            while (r<26 && freqs[r]-freqs[i]<=k) {
                sm+=freqs[r];
                r++;
            }
            rt=min(rt, (int)word.size()-sm-(freqs[i]+k)*(26-r));
            sm-=freqs[i];
        }
        return rt;
    }
};