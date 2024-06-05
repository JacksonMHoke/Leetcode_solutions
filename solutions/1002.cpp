// 1002. Find Common Characters
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> rt;
        vector<int> min_freq(26, INT_MAX);
        for (int i=0; i<words.size(); ++i) {
            vector<int> freq(26);
            for (auto c : words[i])
                freq[c-'a']++;
            for (int j=0; j<26; ++j)
                min_freq[j]=min(min_freq[j], freq[j]);
        }

        for (int i=0; i<26; ++i)
            while (min_freq[i]--)
                rt.push_back(string(1, i+'a'));
        return rt;
    }
};