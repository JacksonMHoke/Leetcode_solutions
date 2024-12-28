// 689. Maximum Sum of 3 Non-Overlapping Subarrays
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> prefix(n+1);
        for (int i=1; i<=n; ++i) {
            prefix[i]=prefix[i-1]+nums[i-1];
        }

        vector<vector<pair<long long, int>>> dp(4, vector<pair<long long, int>>(n+1));
        for (int i=1; i<=3; ++i) {
            for (int j=(i-1)*k+1; j<=n-k+1; ++j) {
                dp[i][j].first=prefix[j+k-1]-prefix[j-1];
                if (j-k>=0)
                    dp[i][j].first+=dp[i-1][j-k].first;
                if (dp[i][j]>dp[i][j-1]) {
                    dp[i][j].second=j;
                } else {
                    dp[i][j].first=dp[i][j-1].first;
                    dp[i][j].second=dp[i][j-1].second;
                }
            }
        }
        vector<int> indexes(3);
        indexes[0]=dp[3][n-k+1].second-1;
        indexes[1]=dp[2][indexes[0]-k+1].second-1;
        indexes[2]=dp[1][indexes[1]-k+1].second-1;
        reverse(indexes.begin(), indexes.end());
        return indexes;
    }
};