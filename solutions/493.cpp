// 493. Reverse Pairs
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        n=nums.size();
        segTree.resize(n*2);

        vector<pair<int, int>> sorted(n);
        for (int i=0; i<n; ++i)
            sorted[i]={nums[i], i};
        sort(sorted.begin(), sorted.end());

        int l=0, rt=0;
        for (int i=0; i<n; ++i) {
            while (l<n && sorted[l].first*2ll<sorted[i].first)
                update(sorted[l++].second, 1);
            rt+=sumRange(sorted[i].second+1, n-1);
        }
        return rt;
    }
private:
    int n;
    vector<int> segTree;

    void update(int i, int val) {
        i+=n;
        segTree[i]=val;
        while (i>1) {
            i>>=1;
            segTree[i]=segTree[i*2]+segTree[i*2+1];
        }
    }

    int sumRange(int l, int r) {
        int sum=0;
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) {
            if (l&1)
                sum+=segTree[l++];
            if (!(r&1))
                sum+=segTree[r--];
        }
        return sum;
    }
};