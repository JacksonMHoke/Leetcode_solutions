// 1915. Number of Wonderful Substrings
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int> map;
        vector<int> dp(word.length()+1); //bitmask 1 is odd, 0 is even
        int curr=0;
        long long rt=0;
        for (int i=0; i<word.length(); ++i) {
            curr^=1<<(word[i]-'a');
            dp[i+1]=curr;
            map[curr]++;
        }

        for (int i=1; i<=word.length(); ++i) {
            rt+=map[dp[i-1]];
            for (int k=0; k<10; ++k) {
                rt+=map[dp[i-1]^(1<<k)];
            }
            map[dp[i]]--;
        }
        return rt;
    }
};