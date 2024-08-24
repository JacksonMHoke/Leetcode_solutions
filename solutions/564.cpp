// 564 Find the Closest Palindrome
class Solution {
public:
    bool isPalindrome(long long n) {
        string s=to_string(n);
        for (int i=0; i<s.length()/2; ++i)
            if (s[i]!=s[s.length()-1-i])
                return false;
        return true;
    }

    string nearestPalindromic(string n) {
        long long num=stoll(n);
        int digits=n.length();
        for (int i=0; i<digits/2; ++i)
            n[digits-1-i]=n[i];
        long long mirrored=stoll(n);

        vector<long long> cands;
        cands.push_back((long long)pow(10,digits-1)-1);
        cands.push_back((long long)pow(10,digits)+1);
        cands.push_back(mirrored);
        long long pow=1;
        for (int i=0; i<digits/2; ++i)
            pow*=10;
        if (digits%2) {
            cands.push_back(mirrored-pow);
            cands.push_back(mirrored+pow);
        } else {
            cands.push_back(mirrored-pow-pow/10);
            cands.push_back(mirrored-pow/10-pow/100);
            cands.push_back(mirrored+pow+pow/10);
        }
        long long diff=LLONG_MAX;
        long long best=LLONG_MAX;
        for (auto cand : cands) {
            if (cand==num || !isPalindrome(cand))
                continue;
            
            if (diff==abs(cand-num))
                best=min(cand, best);
            else if (diff>abs(cand-num)) {
                best=cand;
                diff=abs(cand-num);
            }
        }
        return to_string(best);
    }
};