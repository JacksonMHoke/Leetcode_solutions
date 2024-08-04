// 1508. Range Sum of Sorted Subarray Sums
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int MOD=1e9+7;
        vector<int> range_sums;
        for (int i=0; i<n; ++i) {
            int curr_sum=0;
            for (int j=i; j<n; ++j) {
                curr_sum+=nums[j];
                range_sums.push_back(curr_sum);
            }
        }
        sort(range_sums.begin(), range_sums.end());
        int rt=0;
        for (int i=left-1; i<right; ++i)
            rt=(rt+range_sums[i])%MOD;
        return rt;
    }
};