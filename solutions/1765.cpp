// 1765. Map of Highest Peak
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size(), m=isWater[0].size();
        vector<vector<int>> rt(n, vector<int>(m, -1));
        queue<array<int, 3>> bfs;
        vector<int> dirs{0,1,0,-1,0};
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (isWater[i][j]==1) {
                    bfs.push({0, i, j});
                    rt[i][j]=0;
                }
            }
        }

        while (!bfs.empty()) {
            auto [height, i, j]=bfs.front();
            bfs.pop();
            for (int d=0; d<4; ++d) {
                int x=i+dirs[d], y=j+dirs[d+1];
                if (x<0 || x>=n || y<0 || y>=m || rt[x][y]!=-1)
                    continue;
                rt[x][y]=height+1;
                bfs.push({height+1, x, y});
            }
        }
        return rt;
    }
};