// 1072. Flip Columns For Maximum Number of Equal Rows
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> freq;
        int rt=0;
        for (int i=0; i<matrix.size(); ++i) {
            int first=matrix[i][0];
            string curr="";
            for (int j=0; j<matrix[i].size(); ++j) {
                curr+=(matrix[i][j]==first)? '0': '1';
            }
            freq[curr]++;
            rt=max(freq[curr], rt);
        }
        return rt;
    }
};