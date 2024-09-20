// 214. Shortest Palindrome
class Solution {
public:
    bool isPalindrome(string& s) {
        int n=s.length();
        for (int i=0; i<s.length()/2; ++i) {
            if (s[i]!=s[n-i-1])
                return false;
        }
        return true;
    }
    string shortestPalindrome(string s) {
        if (isPalindrome(s))
            return s;

        string prefix=s.substr(0, (s.length()+1)/2);
        vector<int> skips(prefix.size()+1);
        skips[0]=-1;

        int i=1, matches=0;
        while (i<prefix.size()) {
            if (prefix[i]==prefix[matches])
                skips[++i]=++matches;
            else if (matches>0)
                matches=skips[matches];
            else
                skips[++i]=0;
        }

        i=s.length()-1, matches=0;
        int right=s.length()-1;
        while (i>=0) {
            if (s[i]==prefix[matches]) {
                if (i==matches || i+1==matches) {
                    string rt=s.substr(right+1);
                    reverse(rt.begin(), rt.end());
                    return rt+s;
                }
                matches++;
                i--;
            } else if (matches>0) {
                right=right-matches+skips[matches];
                matches=skips[matches];
            } else {
                i--;
                right=i;
            }
        }

        return s;
    }
};