// 1208. Get Equal Substrings Within Budget
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l=0, r=0, rt=0, cost=0, n=s.length();
        while (r<n) {
            while (r<n && cost+abs(s[r]-t[r])<=maxCost) {
                cost+=abs(s[r]-t[r++]);
            }
            rt=max(rt, r-l);
            cost-=abs(s[l]-t[l++]);
        }
        return rt;
    }
};