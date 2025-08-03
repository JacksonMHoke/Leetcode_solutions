// 2561. Rearranging Fruits
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        long long rt=0;
        int mn=INT_MAX;
        unordered_map<int, int> freqs1, freqs2;
        for (int i=0; i<basket1.size(); ++i) {
            freqs1[basket1[i]]++;
            freqs2[basket2[i]]++;
            mn=min({basket1[i], basket2[i], mn});
        }
        vector<int> b1, b2;
        for (auto pair : freqs1) {
            int val=pair.first, freq=pair.second;
            if ((freq+freqs2[val])%2)
                return -1;
            if (freq>freqs2[val])
                b1.insert(b1.end(), (freq-freqs2[val])/2, val);
        }
        for (auto pair : freqs2) {
            int val=pair.first, freq=pair.second;
            if ((freq+freqs1[val])%2)
                return -1;
            if (freq>freqs1[val])
                b2.insert(b2.end(), (freq-freqs1[val])/2, val);
        }

        sort(b1.begin(), b1.end());
        sort(b2.begin(), b2.end());
        assert(b1.size()==b2.size());

        int n=b1.size();
        for (int i=0; i<b1.size(); ++i)
            rt+=min(mn*2, min(b1[i], b2[n-1-i]));

        return rt;
    }
};