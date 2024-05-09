// 3075. Maximize Happiness of Selected Children
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int n=happiness.size();
        long long rt=0;
        for (int i=n-1; i>=0 && k>0; --i, --k) {
            rt+=max(happiness[i]-(n-i-1), 0);
        }
        return rt;
    }
};