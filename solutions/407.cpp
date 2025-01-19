// 407. Trapping Rain Water II
class Solution {
public:
    vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
    bool contained(vector<vector<int>>& heightMap, vector<bool>& visited, int i, int j, int l) {
        if (i<0 || i>=heightMap.size() || j<0 || j>=heightMap[0].size())
            return false;
        if (heightMap[i][j]>=l || visited[i*heightMap[0].size()+j])
            return true;
        visited[i*heightMap[0].size()+j]=true;
        for (int d=0; d<dirs.size(); ++d) {
            if (!contained(heightMap, visited, i+dirs[d][0], j+dirs[d][1], l))
                return false;
        }
        return true;
    }

    int fill(vector<vector<int>>& heightMap, vector<vector<int>>& waterMap, vector<bool>& visited, int i, int j, int l) {
        if (i<0 || i>=heightMap.size() || j<0 || j>=heightMap[0].size())
            return 0;
        if (heightMap[i][j]>=l || visited[i*heightMap[0].size()+j])
            return 0;
        visited[i*heightMap[0].size()+j]=true;
        waterMap[i][j]=l;
        int rt=0;
        for (int d=0; d<dirs.size(); ++d) {
            rt+=fill(heightMap, waterMap, visited, i+dirs[d][0], j+dirs[d][1], l);
        }
        return rt+l-heightMap[i][j];
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<pair<int, int>> pq;
        int n=heightMap.size(), m=heightMap[0].size();
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                pq.push({heightMap[i][j], i*m+j});
        vector<vector<int>> waterMap(n, vector<int>(m, 0));
        int rt=0;
        while (!pq.empty()) {
            int i=pq.top().second/m, j=pq.top().second%m;
            pq.pop();
            for (int d=0; d<dirs.size(); ++d) {
                int x=i+dirs[d][0], y=j+dirs[d][1];
                if (x<0 || x>=n || y<0 || y>=m)
                    continue;
                vector<bool> visited(m*n, false);
                if (waterMap[x][y]>=heightMap[x][y] || !contained(heightMap, visited, x, y, heightMap[i][j]))
                    continue;
                
                vector<bool> visitedFill(m*n, false);
                rt+=fill(heightMap, waterMap, visitedFill, x, y, heightMap[i][j]);
            }
        }
        return rt;
    }
};