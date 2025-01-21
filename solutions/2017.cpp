// 2017. Grid Game
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long best=LLONG_MAX, top=accumulate(grid[0].begin(), grid[0].end(), 0LL), bottom=0;
        for (int i=0; i<grid[0].size(); ++i) {
            top-=grid[0][i];
            best=min(best, max(top, bottom));
            bottom+=grid[1][i];
        }
        return best;
    }
};