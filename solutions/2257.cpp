// 2257. Count Unguarded Cells in the Grid
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        unordered_set<int> guarded;
        unordered_set<int> is_guard;
        unordered_set<int> is_wall;
        for (int i=0; i<guards.size(); ++i)
            is_guard.insert(guards[i][0]*n+guards[i][1]);
        for (int i=0; i<walls.size(); ++i)
            is_wall.insert(walls[i][0]*n+walls[i][1]);
        vector<pair<int, int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
        for (auto loc : is_guard) {
            for (auto& [x, y] : dirs) {
                int i=loc/n+x, j=loc%n+y;
                while (i>=0 && i<m && j>=0 && j<n && !is_guard.contains(i*n+j) && !is_wall.contains(i*n+j)) {
                    guarded.insert(i*n+j);
                    i+=x;
                    j+=y;
                }
            }
        }
        return m*n-guarded.size()-guards.size()-walls.size();
    }
};