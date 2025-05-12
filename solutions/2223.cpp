//2223. Sum of Scores of Built Strings
// Altered KMP attempt
// Now understand where KMP array fails
// We miss the bits that arent necessarily matching up till the border, but are a suffix that matches the prefix
// We need to find a new prev array that points back to those correctly or accounts for them
class Solution {
    public:
        long long sumScores(string s) {
            long long rt=0;
            vector<int> dp(s.length(), -1);
            int curr=-1;
            for (int i=1; i<s.length(); ++i) {
                while (curr>=0 && s[curr+1]!=s[i]) {
                    cout << "FALLING BACK TO " << dp[curr] << endl;
                    curr=dp[curr];
                }
                if (s[i]==s[curr+1])
                    curr++;
                dp[i]=curr;
            }
            while (curr>=0) {
                cout << "FALLING BACK TO " << dp[curr] << endl;
                rt+=curr+1;
                curr=dp[curr];
            }
            for (int i=0; i<dp.size(); ++i)
                cout << dp[i] << " ";
            return rt+s.length();
        }
    };