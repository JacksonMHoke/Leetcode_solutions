// 1289. Minimum Falling Path Sum II
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp1(n, vector<int>(n, 200000));
        vector<vector<int>> dp2(n, vector<int>(n, 200000));
        dp1[0]=dp2[0]=grid[0];
        for (int i=1; i<n; ++i) {
            for (int j=1; j<n; ++j) {
                dp1[i-1][j]=min(dp1[i-1][j], dp1[i-1][j-1]);
                dp2[i-1][n-j-1]=min(dp2[i-1][n-j-1], dp2[i-1][n-j]);
            }

            dp1[i][0]=grid[i][0]+dp2[i-1][1];
            dp2[i][n-1]=grid[i][n-1]+dp1[i-1][n-2];

            for (int j=1; j<n-1; ++j) {
                dp1[i][j]=grid[i][j]+min(dp1[i-1][j-1], dp2[i-1][j+1]);
                dp2[i][j]=dp1[i][j];
            }
        }

        return min(*min_element(dp1[n-1].begin(), dp1[n-1].end()), dp2[n-1][n-1]);
    }
};