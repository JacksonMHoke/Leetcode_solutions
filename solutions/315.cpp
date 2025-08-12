// 315. Count of Smaller Numbers After Self
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        n=nums.size();
        segTree.resize(n*2);

        vector<pair<int, int>> pairs(n);
        for (int i=0; i<nums.size(); ++i)
            pairs[i]={nums[i], i};
        sort(pairs.begin(), pairs.end());
        vector<int> rt(n);
        for (int i=0; i<pairs.size(); ++i) {
            rt[pairs[i].second]=sumRange(pairs[i].second, n-1);
            update(pairs[i].second, 1);
        }
        return rt;
    }
private:
    vector<int> segTree;
    int n;

    void update(int i, int val) {
        i+=n;
        segTree[i]=val;
        while (i>1) {
            i/=2;
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