// 2902. Count of Sub-Multisets With Bounded Sum
class Solution {
    public:
        int countSubMultisets(vector<int>& nums, int l, int r) {
            sort(begin(nums), end(nums));
            int MOD=1e9+7;
            multiset<int> ms(begin(nums), end(nums));
            vector<vector<int>> dp(set<int>(begin(nums), end(nums)).size()+1, vector<int>(r+1));
            dp[0][0]=1;
            for (int i=1; i<dp.size(); ++i) {
                int num=*begin(ms), curr=0, count=ms.count(num);
                if (num==0) {
                    dp[i][0]=count+1;
                    ms.erase(num);
                    continue;
                }
                vector<int> window(num);
                for (int j=0; j<=r; ++j) {
                    if (j-num>=0)
                        window[j%num]=(window[j%num]+dp[i-1][j-num])%MOD;
                    if (j-num*(count+1)>=0)
                        window[j%num]=(window[j%num]-dp[i-1][j-num*(count+1)])%MOD;
                    window[j%num]=(window[j%num]+MOD)%MOD;
                    dp[i][j]=(window[j%num]+dp[i-1][j])%MOD;
                }
                ms.erase(num);
            }
    
            int sum=0;
            for (int i=l; i<=r; ++i)
                sum=(sum+dp.back()[i])%MOD;
    
            return sum;
        }
    };
    
    //   1 2 2 3
    // 0 1 1 1 1
    // 1 1 1 1 1
    // 2 0 1 2 2
    // 3 0 1 2 3
    // 4 0 0 1 2
    // 5 0 0 1 3
    // 6 0 0 0 2
    //     2
    //   1 2 3
    // 0 1 1 1
    // 1 1 1 1
    // 2 0 1 1
    // 3 0 1 2
    // 4 0 1 2
    // 5 0 1 2
    // 6 0 0 1