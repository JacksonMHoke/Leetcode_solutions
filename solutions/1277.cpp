// 1277. Count Square Submatrices with All Ones
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size(), rt=0;
        vector<vector<int>> dp(n, vector<int>(m));
        vector<vector<int>> consecInCol(n, vector<int>(m));
        vector<vector<int>> consecInRow(n, vector<int>(m));

        for (int i=0; i<n; ++i)  {
            consecInRow[i][m-1]=matrix[i][m-1];
            rt+=matrix[i][m-1];
            dp[i][m-1]=matrix[i][m-1];
        }
        for (int j=0; j<m; ++j) {
            consecInCol[n-1][j]=matrix[n-1][j];
            rt+=matrix[n-1][j];
            dp[n-1][j]=matrix[n-1][j];
        }

        for (int i=n-2; i>=0; --i) {
            for (int j=m-2; j>=0; --j) {
                if (matrix[i][j]==1) {
                    consecInRow[i][j]=consecInRow[i][j+1]+1;
                    consecInCol[i][j]=consecInCol[i+1][j]+1;
                }
            }
        }

        for (int i=n-2; i>=0; --i) {
            for (int j=m-2; j>=0; --j) {
                dp[i][j]=min(consecInRow[i][j], min(consecInCol[i][j], 1+dp[i+1][j+1]));
                rt+=dp[i][j];
            }
        }

        return rt-matrix[n-1][m-1];
    }
};