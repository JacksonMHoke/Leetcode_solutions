// 840. Magic Squares In Grid
class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int i, int j) {
        if (i+2>=grid.size() || j+2>=grid[i].size())
            return false;
        int sum=grid[i][j]+grid[i][j+1]+grid[i][j+2];
        for (int r=i+1; r<i+3; ++r) {
            if (grid[r][j]+grid[r][j+1]+grid[r][j+2]!=sum)
                return false;
        }
        int bitmask=0;
        for (int c=j; c<j+3; ++c) {
            if (grid[i][c]+grid[i+1][c]+grid[i+2][c]!=sum)
                return false;
            bitmask|=1<<(grid[i][c]);
            bitmask|=1<<(grid[i+1][c]);
            bitmask|=1<<(grid[i+2][c]);
        }

        if (grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]!=sum || grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2]!=sum)
            return false;
        
        return bitmask==(1<<10)-2;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rt=0;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[i].size(); ++j) {
                rt+=isMagicSquare(grid, i, j);
            }
        }
        return rt;
    }
};