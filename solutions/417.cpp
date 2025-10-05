// 417. Pacific Atlantic Water Flow
class Solution {
public:
    vector<vector<bool>> bfs(vector<vector<int>>& heights, int corner) {
        int n=heights.size(), m=heights[0].size();
        vector<int> dirs{0, 1, 0, -1, 0};
        vector<vector<bool>> visited(n, vector<bool>(m));

        queue<pair<int, int>> bfs;
        for (int i=0; i<n; ++i)
            bfs.push({i, (m-1)*corner});
        for (int j=0; j<m; ++j)
            bfs.push({(n-1)*corner, j});

        while (!bfs.empty()) {
            auto [x, y]=bfs.front();
            bfs.pop();

            visited[x][y]=true;

            for (int i=0; i<dirs.size()-1; ++i) {
                int nX=x+dirs[i], nY=y+dirs[i+1];
                if (nX<0 || nX>=n || nY<0 || nY>=m || visited[nX][nY] || heights[nX][nY]<heights[x][y])
                    continue;
                visited[nX][nY]=true;
                bfs.push({nX, nY});
            }
        }

        return visited;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific=bfs(heights, 0);
        vector<vector<bool>> atlantic=bfs(heights, 1);
        vector<vector<int>> rt;
        for (int i=0; i<pacific.size(); ++i) {
            for (int j=0; j<pacific[0].size(); ++j) {
                if (pacific[i][j] && atlantic[i][j])
                    rt.push_back({i, j});
            }
        }
        return rt;
    }
};