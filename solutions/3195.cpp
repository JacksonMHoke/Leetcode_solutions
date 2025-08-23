// 3195. Find the Minimum Area to Cover All Ones I
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int t=INT_MAX, b=0, l=INT_MAX, r=0;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[i].size(); ++j) {
                if (grid[i][j]) {
                    t=min(t, i);
                    b=max(b, i);
                    l=min(l, j);
                    r=max(r, j);
                }
            }
        }
        return (b-t+1)*(r-l+1);
    }
};