// 131. Palindrome Partitioning
class Solution {
public:
    void backtrack(string& s, vector<vector<string>>& rt, vector<vector<int>>& pals, vector<string>& curr, int i) {
        if (i>=s.length()) {
            rt.push_back(curr);
            return;
        }

        for (int j=0; j<pals[i].size(); ++j) {
            curr.push_back(s.substr(i, pals[i][j]-i+1));
            backtrack(s, rt, pals, curr, pals[i][j]+1);
            curr.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<int>> pals(n);
        for (int i=0; i<n; ++i) {
            int j=0;
            while (i-j>=0 && i+j<n && s[i-j]==s[i+j])
                pals[i-j].push_back(i+j), j++;
            j=0;
            while (i-j>=0 && i+j+1<n && s[i-j]==s[i+j+1])
                pals[i-j].push_back(i+j+1), j++;
        }

        vector<vector<string>> rt;
        vector<string> curr;
        backtrack(s, rt, pals, curr, 0);
        return rt;
    }
};