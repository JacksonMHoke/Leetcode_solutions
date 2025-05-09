// 1872. Stone Game VIII
class Solution {
    public:
        int stoneGameVIII(vector<int>& stones) {
            int n=stones.size();
            for (int i=1; i<stones.size(); ++i)
                stones[i]+=stones[i-1];
            int dp=stones[n-1];
            for (int i=n-3; i>=0; --i)
                dp=max(dp, stones[i+1]-dp);
            return dp;
        }
    };
    