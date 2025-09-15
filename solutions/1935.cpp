// 1935. Maximum Number of Words You Can Type
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        text+=' ';
        vector<int> broken(26);
        for (auto c : brokenLetters)
            broken[c-'a']++;
        bool cant=false;
        int rt=0;
        for (int i=0; i<text.length(); ++i) {
            if (text[i]==' ') {
                rt+=!cant;
                cant=false;
            } else if (broken[text[i]-'a'])
                cant=true;
        }
        return rt;
    }
};