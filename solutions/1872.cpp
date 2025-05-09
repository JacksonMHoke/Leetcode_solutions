// 1872. Stone Game VIII
class Solution {
    public:
        int stoneGameVIII(vector<int>& stones) {
            vector<int> dp(stones.size(), INT_MIN);
            for (int i=1; i<stones.size(); ++i)
                stones[i]+=stones[i-1];
    
            if (stones.size()==2)
                return stones.back();
    
            dp[stones.size()-2]=stones.back();
            dp.back()=0;
            for (int i=(int)stones.size()-3; i>=0; --i) {
                dp[i]=max(dp[i+1], stones[i+1]-dp[i+1]);
            }
    
            return dp[0];
        }
    };
    