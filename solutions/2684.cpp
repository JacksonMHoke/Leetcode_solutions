// 2684. Maximum Number of Moves in a Grid
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        int rt=0;
        for (int i=0; i<n; ++i) dp[i][0]=1;

        for (int j=1; j<m; ++j) {
            for (int i=0; i<n; ++i) {
                for (int k=max(i-1, 0); k<=min(i+1, n-1); ++k) {
                    if (grid[i][j]>grid[k][j-1] && dp[k][j-1])
                        dp[i][j]=dp[k][j-1]+1;
                }
                rt=max(rt, dp[i][j]);
            }
        }
        return max(rt-1, 0);
    }
};