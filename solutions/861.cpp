// 861. Score After Flipping Matrix
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        for (int i=0; i<n; ++i) {
            if (grid[i][0]==0) {
                for (int j=0; j<m; ++j)
                    grid[i][j]=!grid[i][j];
            }
        }
        int rt=0;
        for (int j=0; j<m; ++j) {
            int num_ones=0;
            for (int i=0; i<n; ++i)
                num_ones+=grid[i][j]==1;
            rt+=(1<<(m-j-1))*max(num_ones, n-num_ones);
        }
        return rt;
    }
};