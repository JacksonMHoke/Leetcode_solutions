// 3133. Minimum Array End
class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        long long curr=1, nPos=1, rt=x;
        while (nPos<=n) {
            if ((curr&x)==0) {
                if (nPos&n)
                    rt+=curr;
                nPos<<=1;
            }
            curr<<=1;
        }
        return rt;
    }
};