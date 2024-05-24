// 1255. Maximum Score Words Formed by Letters

class Solution {
public:
    int backtrack(vector<string>& words, vector<int>& score, vector<int>& freq, int i) {
        if (i>=words.size())
            return 0;
        int rt=0;
        for (int j=i; j<words.size(); ++j) {
            int k=0, word_score=0;
            for (k=0; k<words[j].length(); ++k) {
                int l=words[j][k]-'a';
                freq[l]--;
                word_score+=score[l];
                if (freq[l]<0)
                    break;
            }

            if (k==words[j].length()) {
                k--;
                rt=max(rt, word_score+backtrack(words, score, freq, j+1));
            }

            while (k>=0) {
                freq[words[j][k]-'a']++;
                k--;
            }
        }
        return rt;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26);
        for (auto l : letters)
            freq[l-'a']++;
        return backtrack(words, score, freq, 0);
    }
};