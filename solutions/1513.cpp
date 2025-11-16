// 1513. Number of Substrings With Only 1s
class Solution {
public:
    int numSub(string s) {
        int cnt=0, rt=0;
        for (char c : s) {
            cnt=(c=='1')? cnt+1: 0;
            rt=(rt+cnt)%1000000007;
        }
        return rt;
    }
};