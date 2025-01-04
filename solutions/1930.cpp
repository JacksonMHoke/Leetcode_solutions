// 1930. Unique Length-3 Palindromic Subsequences
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> start(26, INT_MAX);
        vector<int> end(26);
        for (int i=0; i<s.length(); ++i) {
            end[s[i]-'a'] = i;
            start[s[i]-'a'] = min(start[s[i]-'a'], i);
        }
        vector<vector<bool>> used(26, vector<bool>(26));
        int rt=0;
        for (int i=0; i<s.length(); ++i) {
            for (int j=0; j<26; ++j) {
                if (!used[j][s[i]-'a'] && i>start[j] && i<end[j]) {
                    used[j][s[i]-'a'] = true;
                    rt++;
                }
            }
        }
        return rt;
    }
};