// 567. Permutation in String
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26);
        for (auto c : s1)
            freq[c-'a']++;
        
        int l=0, r=0;
        while (r<s2.length()) {
            freq[s2[r]-'a']--;
            while (l<s2.length() && freq[s2[r]-'a']<0)
                freq[s2[l++]-'a']+=1;
            if (l<=r && r-l+1==s1.length())
                return true;
            r++;
        }
        return false;
    }
};