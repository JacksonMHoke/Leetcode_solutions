// 1992. Find All Groups of Farmland
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size(), m=land[0].size();
        vector<vector<int>> rt;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (land[i][j]==0)
                    continue;
                if (i>0)
                    land[i][j]=land[i-1][j]%1000+1;
                if (j>0)
                    land[i][j]+=(land[i][j-1]/1000+1)*1000;
                else
                    land[i][j]+=1000;
                if ((i==n-1 || land[i+1][j]==0) && (j==m-1 || land[i][j+1]==0))
                    rt.push_back({i-land[i][j]%1000+1, j-land[i][j]/1000+1, i, j});
            }
        }
        return rt;
    }
};