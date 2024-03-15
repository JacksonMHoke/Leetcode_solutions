//843. Guess The Word
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int diff(string& s1, string& s2) {
        int d=0;
        for (int i=0; i<s1.length(); ++i) {
            d+=(s1[i]!=s2[i]);
        }
        return d;
    }

    void findSecretWord(vector<string>& words, Master& master) {
        vector<int> valid_options;
        for (int i=0; i<words.size(); ++i) {
            valid_options.push_back(i);
        }
        srand(time(NULL));
        for (int l=0; l<100; ++l) {
            int curr=valid_options[rand()%valid_options.size()];
            int overlap=master.guess(words[curr]);
            if (overlap==6)
                return;
            int j=0, k=0;
            vector<int> new_valid;
            vector<int> diffs;
            for (int i=0; i<valid_options.size(); ++i) {
                if (diff(words[curr], words[valid_options[i]])==6-overlap)
                    new_valid.push_back(valid_options[i]);
            }
            valid_options=new_valid;
        }

        return;
    }
};