// 673. Number of Longest Increasing Subsequence
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        n=nums.size();
        maxTree.resize(n*2);
        freqTree.resize(n*2);
        set<int> distinct(nums.begin(), nums.end());
        unordered_map<int, int> map;
        int j=0;
        for (auto val : distinct)
            map[val]=j++;
        
        for (auto num : nums)
            update(map[num]);

        return query(0, n-1).second;
    }
private:
    vector<int> maxTree;
    vector<int> freqTree;
    int n;

    void update(int i) {
        auto [mx, freq]=query(0, i-1);
        i+=n;
        if (maxTree[i]==mx+1)
            freqTree[i]+=max(freq, 1);
        else
            freqTree[i]=max(freq, 1);
        maxTree[i]=mx+1;
        while (i>1) {
            i>>=1;
            maxTree[i]=max(maxTree[i*2], maxTree[i*2+1]);
            freqTree[i]=(maxTree[i*2]==maxTree[i])*freqTree[i*2]+(maxTree[i*2+1]==maxTree[i])*freqTree[i*2+1];
        }
    }

    pair<int, int> query(int l, int r) {
        int mx=0, freq=0;
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) {
            if (l&1) {
                if (maxTree[l]>mx) {
                    freq=freqTree[l];
                    mx=maxTree[l];
                } else if (maxTree[l]==mx)
                    freq+=freqTree[l];
                l++;
            }

            if (!(r&1)) {
                if (maxTree[r]>mx) {
                    freq=freqTree[r];
                    mx=maxTree[r];
                } else if (maxTree[r]==mx)
                    freq+=freqTree[r];
                r--;
            }
        }
        return {mx, freq};
    }
};