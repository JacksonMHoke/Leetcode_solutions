// 1395. Count Number of Teams
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int rt=0, n=rating.size();
        vector<int> gt(n), lt(n);
        for (int i=0; i<n; ++i) {
            for (int j=i-1; j>=0; --j) {
                if (rating[j]<rating[i]) {
                    rt+=lt[j];
                    lt[i]++;
                } else if (rating[j]>rating[i]) {
                    rt+=gt[j];
                    gt[i]++;
                }
            }
        }
        return rt;
    }
};