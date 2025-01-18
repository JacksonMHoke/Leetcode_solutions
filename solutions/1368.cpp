// 1368. Minimum Cost to Make at Least One Valid Path in a Grid
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,0});
        vector<vector<int>> dists(n, vector<int>(m, INT_MAX));
        vector<vector<int>> dirs{{0,0}, {0,1}, {0,-1}, {1,0}, {-1,0}};
        while (!pq.empty()) {
            int dist=pq.top().first;
            int i=pq.top().second/m, j=pq.top().second%m;
            pq.pop();

            if (i==n-1 && j==m-1)
                return dist;
            if (dists[i][j]<dist)
                continue;

            for (int d=0; d<dirs.size(); ++d) {
                int x=i+dirs[d][0], y=j+dirs[d][1];
                if (x>=0 && x<n && y>=0 && y<m && dists[x][y]>dist+(d!=grid[i][j])) {
                    dists[x][y]=dist+(d!=grid[i][j]);
                    pq.push({dist+(d!=grid[i][j]), x*m+y});
                }
            }
        }
        return -1;
    }
};