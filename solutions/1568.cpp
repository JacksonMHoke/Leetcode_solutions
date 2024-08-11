// 1568. Minimum Number of Days to Disconnect Island
class Solution {
public:
    int n, m;
    vector<pair<int, int>> findNeighbors(vector<vector<int>>& grid, int i, int j) {
        vector<pair<int, int>> rt;
        if (i-1>=0 && grid[i-1][j]!=0)
            rt.push_back({i-1, j});
        if (i+1<n && grid[i+1][j]!=0)
            rt.push_back({i+1, j});
        if (j-1>=0 && grid[i][j-1]!=0)
            rt.push_back({i, j-1});
        if (j+1<m && grid[i][j+1]!=0)
            rt.push_back({i, j+1});
        return rt;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int curr) {
        if (i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 || grid[i][j]==curr)
            return;
        grid[i][j]=curr;
        dfs(grid, i+1, j, curr);
        dfs(grid, i-1, j, curr);
        dfs(grid, i, j+1, curr);
        dfs(grid, i, j-1, curr);
        return;
    }

    int minDays(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        int curr=2;
        bool found;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (grid[i][j]==1 && curr==2)
                    dfs(grid, i, j, curr++);
                if (grid[i][j]==1 && curr>2)
                    return 0;
            }
        }

        if (curr==2)
            return 0;

        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (grid[i][j]!=0) {
                    vector<pair<int, int>> neighbors=findNeighbors(grid, i, j);
                    if (neighbors.size()==0)
                        return 1;
                    grid[i][j]=0;
                    dfs(grid, neighbors[0].first, neighbors[0].second, curr);
                    grid[i][j]=1;
                    bool flag=false;
                    for (auto& [x, y] : neighbors) {
                        if (grid[x][y]!=curr)
                            flag=true;
                    }
                    if (flag)
                        return 1;
                    curr++;
                }
            }
        }
        return 2;
    }
};