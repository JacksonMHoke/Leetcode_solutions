// 85. Maximal Rectangle
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (matrix[i][j]=='1')
                    dp[i][j]=1+dp[i][max(0, j-1)];
            }
        }
        int max_area=0;
        vector<vector<int>> up(n, vector<int>(m));
        vector<vector<int>> down(n, vector<int>(m));
        for (int j=0; j<m; ++j) {
            stack<int> s;
            for (int i=0; i<n; ++i) {
                while (!s.empty() && dp[s.top()][j]>=dp[i][j])
                    s.pop();
                up[i][j]=(s.empty()) ? i+1 : i-s.top();
                s.push(i);
            }
            s=stack<int>();
            for (int i=n-1; i>=0; --i) {
                while (!s.empty() && dp[s.top()][j]>=dp[i][j])
                    s.pop();
                down[i][j]=(s.empty()) ? n-i : s.top()-i;
                s.push(i);
            }
        }
        
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                max_area=max(max_area, (up[i][j]+down[i][j]-1)*dp[i][j]);
            }
        }
        return max_area;
    }
};