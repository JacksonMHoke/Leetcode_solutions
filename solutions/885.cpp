// 885. Spiral Matrix III
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> rt{{rStart, cStart}};
        vector<int> dirs{1,0,-1,0,1};
        int numFilled=1, r=rStart, c=cStart, dir=0;
        for (int i=0; numFilled<rows*cols; ++i) {
            for (int k=0; k<2; ++k) {
                for (int j=0; j<=i; ++j) {
                    r-=dirs[dir+1];
                    c+=dirs[dir];
                    if (r>=0 && r<rows && c>=0 && c<cols) {
                        rt.push_back({r, c});
                        numFilled++;
                    }
                }
                dir=(dir+1)%4;
            }
        }
        return rt;
    }
};