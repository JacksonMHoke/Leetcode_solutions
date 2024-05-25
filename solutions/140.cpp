// 140. Word Break II
class Solution {
public:
    void backtrack(string& s, unordered_set<string>& dict, vector<string>& rt, string& curr, int i) {
        if (i==s.length()) {
            curr.pop_back();
            rt.push_back(curr);
            return;
        }
        string temp="";
        for (int j=i; j<s.length(); ++j) {
            temp+=s[j];
            if (dict.contains(temp)) {
                string old=curr;
                curr=curr+temp+" ";
                backtrack(s, dict, rt, curr, j+1);
                curr=old;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto& word : wordDict)
            dict.insert(word);
        vector<string> rt;
        string curr;
        backtrack(s, dict, rt, curr, 0);
        return rt;
    }
};