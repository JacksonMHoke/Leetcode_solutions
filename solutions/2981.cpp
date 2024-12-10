// 2981. Find Longest Special Substring That Occurs Thrice I
class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> freq;
        int i=0, n=s.length();
        while (i<n) {
            char c=s[i];
            int j=i;
            while (i<n && s[i]==c)
                i++;
            string curr;
            for (int k=1; k<=i-j+1; ++k) {
                curr+=c;
                freq[curr]+=i-j-k+1;
            }
        }

        int longest=-1;
        for (auto& p : freq) {
            if (p.second>=3)
                longest=max(longest, (int)p.first.length());
        }
        return longest;
    }
};