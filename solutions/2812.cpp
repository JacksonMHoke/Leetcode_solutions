// 2812. Find the Safest Path in a Grid
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        unordered_set<int> visited;
        queue<int> q;
        int n=grid.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]==1) {
                    q.push(1000*i+j);
                    grid[i][j]=0;
                } else {
                    grid[i][j]=100000;
                }
            }
        }

        vector<int> dirs{0,1,0,-1,0};
        while (!q.empty()) {
            int i=q.front()/1000, j=q.front()%1000;
            visited.insert(q.front());
            q.pop();

            for (int k=0; k<dirs.size()-1; ++k) {
                int x=dirs[k]+i, y=dirs[k+1]+j;
                if (x<0 || y<0 || x>=n || y>=n)
                    continue;
                if (visited.find(x*1000+y)==visited.end() && grid[x][y]>grid[i][j]+1) {
                    grid[x][y]=grid[i][j]+1;
                    q.push(x*1000+y);
                }
            }
        }

        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        pq.push({grid[0][0], 0});
        while (!pq.empty()) {
            int i=pq.top().second/1000, j=pq.top().second%1000, safety=pq.top().first;
            pq.pop();
            if (i==n-1 && j==n-1)
                return safety;

            for (int k=0; k<dirs.size()-1; ++k) {
                int x=dirs[k]+i, y=dirs[k+1]+j;
                if (x<0 || y<0 || x>=n || y>=n)
                    continue;
                int newSafety=min(safety, grid[x][y]);
                if (mp[1000*x+y]<newSafety) {
                    mp[1000*x+y]=newSafety;
                    pq.push({newSafety, x*1000+y});
                }
            }
        }
        return 0;
    }
};