// 2516. Take K of Each Character From Left and Right
class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.length(), r=n-1;
        vector<int> frq(3);

        while (r>=0 && (frq[0]<k || frq[1]<k || frq[2]<k)) {
            frq[s[r]-'a']++;
            r--;
        }
        r++;

        if (frq[0]<k || frq[1]<k || frq[2]<k)
            return -1;
        int rt=n-r;

        for (int i=0; i<n; ++i) {
            frq[s[i]-'a']++;
            while (r<n && frq[s[r]-'a']>k) {
                frq[s[r]-'a']--;
                r++;
            }
            rt=min(rt, i+1+n-r);
        }
        return rt;
    }
};