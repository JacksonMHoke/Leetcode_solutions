// 916. Word Subsets
class Solution {
public:
    vector<int> get_freqs(string& word) {
        vector<int> rt(26);
        for (int i=0; i<word.length(); ++i)
            rt[word[i]-'a']--;
        return rt;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> min_freqs(26);
        for (int i=0; i<words2.size(); ++i) {
            vector<int> curr_freqs=get_freqs(words2[i]);
            for (int j=0; j<26; ++j)
                min_freqs[j]=min(min_freqs[j], curr_freqs[j]);
        }
        vector<string> rt;
        for (int i=0; i<words1.size(); ++i) {
            vector<int> curr_freqs=get_freqs(words1[i]);
            rt.push_back(words1[i]);
            for (int j=0; j<26; ++j) {
                if (curr_freqs[j]>min_freqs[j]) {
                    rt.pop_back();
                    break;
                }
            }
        }
        return rt;
    }
};