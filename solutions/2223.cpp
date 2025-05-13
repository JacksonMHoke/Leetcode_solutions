//2223. Sum of Scores of Built Strings
// Altered KMP attempt
// Now understand where KMP array fails
// We miss the bits that arent necessarily matching up till the border, but are a suffix that matches the prefix
// We need to find a new prev array that points back to those correctly or accounts for them
// Got spoiled that Z-score is a sliding window approach. Keep that in mind for next time I am working on this problem.
// Had to cheat a bit to come to the solution, but got fairly close.
// Idea is to try and expand as far right as you can first, and then iterate the left pointer and use the previous lookups at i-L to find out how many matches
// the current i will have. If the number of matches it will have matches all the way to the border, try and expand out as far as possible.
// This way we can find the prefix matches at each suffix in amortized O(1)
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