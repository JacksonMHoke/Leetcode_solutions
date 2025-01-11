// 1400. Construct K Palindrome Strings
class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> odd_freq(26);
        for (int i=0; i<s.length(); ++i)
            odd_freq[s[i]-'a']^=1;
        return s.length()>=k && accumulate(odd_freq.begin(), odd_freq.end(), 0)<=k;
    }
};