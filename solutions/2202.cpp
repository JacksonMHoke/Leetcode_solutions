// 2022. Convert 1D Array Into 2D Array
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m*n!=original.size())
            return {};
        vector<vector<int>> rt(m, vector<int>(n));
        for (int i=0; i<original.size(); ++i)
            rt[i/n][i%n]=original[i];
        return rt;
    }
};