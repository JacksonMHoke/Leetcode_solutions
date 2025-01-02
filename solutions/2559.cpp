// 2559. Count Vowel Strings in Ranges
class Solution {
public:
    bool isvowel(char ch) {
        return (ch == 'a') || (ch == 'e') ||(ch == 'i') ||(ch == 'o') ||(ch == 'u');
    }

    bool valid(string& word) {
        return isvowel(word[0]) && isvowel(word.back());
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size());
        prefix[0]=valid(words[0]);
        for (int i=1; i<words.size(); ++i)
            prefix[i]=prefix[i-1]+valid(words[i]);
        vector<int> rt;
        for (int i=0; i<queries.size(); ++i) {
            int l=queries[i][0], r=queries[i][1];
            if (l==0)
                rt.push_back(prefix[r]);
            else
                rt.push_back(prefix[r]-prefix[l-1]);
        }
        return rt;
    }
};