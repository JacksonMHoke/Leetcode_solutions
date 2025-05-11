//2223. Sum of Scores of Built Strings
// Altered KMP attempt
class Solution {
    public:
        long long sumScores(string s) {
            long long rt=0;
            vector<int> dp(s.length(), -1);
            int curr=-1;
            for (int i=1; i<s.length(); ++i) {
                while (curr>=0 && s[curr+1]!=s[i])
                    curr=dp[curr];
                if (s[i]==s[curr+1])
                    curr++;
                dp[i]=curr;
            }
            bool negative=true;
            for (int i=s.length()-1; i>0; --i) {
                if (s[i]>=0 && negative==false)
                    continue;
                if (dp[i]==-1) {
                    negative=true;
                    continue;
                }
                curr=i;
                while (curr>=0) {
                    curr=dp[curr];
                    rt+=curr+1;
                }
                negative=false;
    
            }
            for (int i=0; i<dp.size(); ++i)
                cout << dp[i] << " ";
            return rt+s.length();
        }
    };