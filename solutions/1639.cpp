// 1639. Number of Ways to Form a Target String Given a Dictionary
class Solution {
public:
    int MOD=1e9+7;
    int numWays(vector<string>& words, string target) {
        //dp[i][j]=number of ways to form the target up to index i using the first j columns
        vector<vector<int>> columnCharMap(words[0].length(), vector<int>(26));
        for (int i=0; i<words[0].length(); ++i) {
            for (int j=0; j<words.size(); ++j) {
                columnCharMap[i][words[j][i]-'a']++;
            }
        }

        vector<vector<long long>> dp(target.length()+1, vector<long long>(words[0].length()+1));
        for (int i=0; i<=words[0].length(); ++i) {
            dp[0][i]=1;
        }

        for (int i=1; i<=target.length(); ++i) {
            for (int j=1; j<=words[0].length(); ++j) {
                dp[i][j]=(dp[i][j-1]+dp[i-1][j-1]*columnCharMap[j-1][target[i-1]-'a'])%MOD;
            }
        }
        return dp[target.length()][words[0].length()];
    }
};