// 1605. Find Valid Matrix Given Row and Column Sums
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size(), m=colSum.size();
        long long currCol=0, nextCol=0;
        vector<vector<int>> rt(n, vector<int>(m));
        for (int i=0; i<n; ++i) {
            currCol+=rowSum[i];
            rt[i][0]=rowSum[i];
        }
        
        for (int j=0; j<m; ++j) {
            for (int i=0; i<n && currCol>colSum[j]; ++i) {
                int transfer=(int)min(currCol-colSum[j], rt[i][j]+0ll);
                currCol-=transfer;
                nextCol+=transfer;
                rt[i][j+1]+=transfer;
                rt[i][j]-=transfer;
            }
            currCol=nextCol;
            nextCol=0;
        }

        return rt;
    }
};