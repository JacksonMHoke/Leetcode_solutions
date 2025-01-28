// 2658. Maximum Number of Fish in a Grid
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (min(i, j)<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return 0;
        return exchange(grid[i][j], 0)+dfs(grid, i+1, j)+dfs(grid, i-1, j)+dfs(grid, i, j+1)+dfs(grid, i, j-1);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int rt=0;
        for (int i=0; i<grid.size(); ++i)
            for (int j=0; j<grid[0].size(); ++j)
                rt=max(rt, dfs(grid, i, j));
        return rt;
    }
};