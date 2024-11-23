// 1861. Rotating the Box
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size(), m=box[0].size();
        vector<vector<char>> rotated(m, vector<char>(n));
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                rotated[j][n-1-i]=box[i][j];
        
        for (int i=0; i<n; ++i) {
            int fallLocation=m-1;
            for (int j=m-1; j>=0; --j) {
                if (rotated[j][i]=='*')
                    fallLocation=j-1;
                if (rotated[j][i]=='#') {
                    swap(rotated[fallLocation--][i], rotated[j][i]);
                }
            }
        }
        return rotated;
    }
};