// 828. Count Unique Characters of All Substrings of a Given String
// Idea is to find number of contributions that each index of s will make to all substrings.
// This can be calculated by keeping track of the next and prev occurence of the char c at s[i]
// if s[j] is the previous occurence and s[k] is the next occurence and s[i] is the current occurence
    // then we can calculate the contribution by (k-i)*(i-j)
    // if you write down an example and try to do it by hand this formula comes fairly intuitively
    // by grouping the different substrings by their starting index
class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> prev(s.length(), -1);
        vector<int> map(26, -1);
        int rt=0;
        for (int i=0; i<s.length(); ++i) {
            int c=s[i]-'A';
            if (map[c]>=0) {
                prev[i]=map[c];
                rt+=(i-map[c])*(map[c]-prev[map[c]]);
            }
            map[c]=i;
        }

        for (int c=0; c<26; ++c) {
            if (map[c]>=0) {
                rt+=(s.length()-map[c])*(map[c]-prev[map[c]]);
            }
        }

        return rt;
    }
};