// 2577. Minimum Time to Visit a Cell In a Grid
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        if (grid[1][0]>1 && grid[0][1]>1)
            return -1;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<int> dirs{0,1,0,-1,0};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            int t=pq.top().first, i=pq.top().second/m, j=pq.top().second%m;
            pq.pop();

            if (t>dist[i][j])
                continue;

            if (i==n-1 && j==m-1)
                return t;
            
            for (int d=0; d<4; ++d) {
                int x=i+dirs[d], y=j+dirs[d+1];
                if (x>=0 && x<n && y>=0 && y<m) {
                    if (t+1>=grid[x][y] && dist[x][y]>t+1) {
                        pq.push({t+1, x*m+y});
                        dist[x][y]=t+1;
                        continue;
                    }

                    if (t+1<grid[x][y]) {
                        int destTime=grid[x][y]+(grid[x][y]-t-1)%2;
                        if (destTime>=dist[x][y])
                            continue;
                        pq.push({destTime, x*m+y});
                    }
                }
            }
        }
        return -1;
    }
};