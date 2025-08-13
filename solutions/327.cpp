// 327. Count of Range Sum
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        n=nums.size();
        segTree.resize((n+1)*2);
        vector<pair<long long, long long>> prefix(n+1);
        for (int i=1; i<n+1; ++i)
            prefix[i]={prefix[i-1].first+nums[i-1], i};
        sort(prefix.begin(), prefix.end());
        int l=n, r=n, rt=0;
        for (int i=n; i>=0; --i) {
            while (l>=0 && prefix[l].first>=prefix[i].first-upper) {
                update(prefix[l--].second, 1);
            }

            while (r>l && prefix[r].first>prefix[i].first-lower) {
                update(prefix[r--].second, 0);
            }

            rt+=sumRange(0, prefix[i].second-1);
        }
        return rt;
    }
private:
    int n;
    vector<int> segTree;

    void update(int i, int val) {
        i+=n+1;
        segTree[i]=val;
        while (i>1) {
            i>>=1;
            segTree[i]=segTree[i*2]+segTree[i*2+1];
        }
    }

    int sumRange(int left, int right) {
        int sum=0;
        for (left+=n+1, right+=n+1; left<=right; left>>=1, right>>=1) {
            if (left&1)
                sum+=segTree[left++];
            if (!(right&1))
                sum+=segTree[right--];
        }
        return sum;
    }
};