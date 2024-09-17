// 1371. Find the Longest Substring Containing Vowels in Even Counts
class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        mp[0]=-1;
        int x=0, rt=0;
        for (int i=0; i<s.length(); ++i) {
            x^=(1<<(s[i]-'a'))&0x104111;
            if (mp.contains(x)) 
                rt=max(rt, i-mp[x]);
            else 
                mp[x]=i;
        }
        return rt;
    }
};