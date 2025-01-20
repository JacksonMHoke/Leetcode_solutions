// 2661. First Completely Painted Row or Column
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<int> map(n*m+1), paintedInRow(n), paintedInCol(m);
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                map[mat[i][j]]=i*m+j;
        
        for (int a=0; a<arr.size(); ++a) {
            int i=map[arr[a]]/m, j=map[arr[a]]%m;
            paintedInRow[i]++;
            paintedInCol[j]++;
            if (paintedInRow[i]>=m || paintedInCol[j]>=n)
                return a;
        }
        return -1;
    }
};