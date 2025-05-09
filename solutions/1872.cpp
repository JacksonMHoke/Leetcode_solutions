// 1872. Stone Game VIII
class Solution {
    public:
        int stoneGameVIII(vector<int>& stones) {
            int n=stones.size();
            vector<int> dp(n);
            dp.back()=0;
            for (int i=1; i<stones.size(); ++i)
                stones[i]+=stones[i-1];
            dp[n-2]=stones[n-1];
            for (int i=n-3; i>=0; --i)
                dp[i]=max(dp[i+1], stones[i+1]-dp[i+1]);
            return dp[0];
        }
    };
    