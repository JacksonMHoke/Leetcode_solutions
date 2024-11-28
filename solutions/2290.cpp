// 2290. Minimum Obstacle Removal to Reach Corner
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), obs=0;
        vector<int> visited(n*m), dirs{0,1,0,-1,0};
        queue<pair<int, int>> curr;
        curr.push({0, 0});
        while (!curr.empty()) {
            queue<pair<int, int>> next;
            while (!curr.empty()) {
                auto [i, j]=curr.front();
                curr.pop();

                if (i==n-1 && j==m-1)
                    return obs;
                
                for (int d=0; d<dirs.size()-1; ++d) {
                    int x=i+dirs[d], y=j+dirs[d+1];
                    if (x>=0 && y>=0 && x<n && y<m && !visited[x*m+y]) {
                        if (grid[x][y]==1)
                            next.push({x, y});
                        else
                            curr.push({x, y});
                        visited[x*m+y]=1;
                    }
                }
            }
            obs++;
            curr=next;
        }
        return -1;
    }
};