// 959. Regions Cut By Slashes
class Solution {
public:
    void fill(vector<string>& square, int i, int j) {
        if (i<0 || j<0 || i>=square.size() || j>=square.size() || square[i][j]!='0')
            return;
        
        square[i][j]='.';
        for (int x=-1; x<=1; ++x) {
            for (int y=-1; y<=1; ++y) {
                char slash=(x*y==1) ? '/' : '\\';
                if (x*y==0) { // if vert or hor movement
                    fill(square, i+x, j+y);
                } else {
                    if (i+x<0 || i+x>=square.size() || j+y<0 || j+y>=square.size())
                        continue;
                    if (square[i+x][j]!=slash || square[i][j+y]!=slash)
                        fill(square, i+x, j+y);
                }
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<string> doubled(n*2, string(n*2, '0'));

        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]=='/') {
                    doubled[i*2][j*2+1]='/';
                    doubled[i*2+1][j*2]='/';
                } else if (grid[i][j]=='\\') {
                    doubled[i*2][j*2]='\\';
                    doubled[i*2+1][j*2+1]='\\';
                }
            }
        }

        int rt=0;
        for (int i=0; i<2*n; ++i) {
            for (int j=0; j<2*n; ++j) {
                if (doubled[i][j]=='0')
                    rt++;
                fill(doubled, i, j);
            }
        }
        return rt;
    }
};