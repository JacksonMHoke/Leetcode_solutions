// 1975. Maximum Matrix Sum
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int closestToZero=INT_MAX, numNegs=0;
        long long sum=0;
        for (int i=0; i<matrix.size(); ++i) {
            for (int j=0; j<matrix[i].size(); ++j) {
                if (matrix[i][j]<0)
                    numNegs++;
                closestToZero=min(closestToZero, abs(matrix[i][j]));
                sum+=abs(matrix[i][j]);
            }
        }
        if (numNegs%2)
            sum-=closestToZero*2;
        return sum;
    }
};