// 2370 Longest Ideal Subsequence
class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26);
        int rt=0;
        for (int i=0; i<s.length(); ++i) {
            char c=s[i]-'a';
            int mx=*max_element(dp.begin()+max(0, c-k), dp.begin()+min(25, c+k)+1);
            dp[c]=mx+1;
            rt=max(rt, dp[c]);
        }
        return rt;
    }
};