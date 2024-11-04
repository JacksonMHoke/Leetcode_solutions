// 3163. String Compression III
class Solution {
public:
    string compressedString(string word) {
        string rt;
        for (int i=0; i<word.length(); ++i) {
            int cnt=1;
            while (i+1<word.length() && word[i]==word[i+1] && cnt<9) {
                i++;
                cnt++;
            }
            rt.push_back('0'+cnt);
            rt.push_back(word[i]);
        }
        return rt;
    }
};