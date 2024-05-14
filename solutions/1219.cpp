// 1219. Path with Maximum Gold
class Solution {
public:
    vector<int> dirs{0,1,0,-1,0};
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j]==1 || grid[i][j]==0)
            return 0;
        int rt=0;
        visited[i][j]=1;

        for (int k=0; k<dirs.size()-1; ++k)
            rt=max(rt, grid[i][j]+dfs(grid, visited, i+dirs[k], j+dirs[k+1]));

        visited[i][j]=-1;
        return rt;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
        int rt=0;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                rt=max(rt, dfs(grid, visited, i, j));
            }
        }
        return rt;
    }
};