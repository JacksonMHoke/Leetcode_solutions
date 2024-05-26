// 552. Student Attendance Record II
class Solution {
public:
    int checkRecord(int n) {
        int MOD=1e9+7;
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(3, vector<int>(n)));
        dp[0][0][0]=dp[0][1][0]=dp[1][0][0]=1;
        for (int day=1; day<n; ++day) {
            for (int ab=0; ab<2; ++ab) {
                for (int l=0; l<3; ++l) {
                    dp[ab][0][day]=(dp[ab][0][day]+dp[ab][l][day-1])%MOD;    // no consec lates without absent yet
                }
                dp[ab][1][day]=dp[ab][0][day-1];                          // 1 consec late without absent
                dp[ab][2][day]=dp[ab][1][day-1];
            }

            for (int l=0; l<3; ++l)
                dp[1][0][day]=(dp[1][0][day]+dp[0][l][day-1])%MOD;
        }
        int rt=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<3; ++j) {
                rt=(rt+dp[i][j].back())%MOD;
            }
        }
        return rt;
    }
};