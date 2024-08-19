// 650. 2 Keys Keyboard
class Solution {
public:
    int minSteps(int n) {
        int rt=0, curr=n;
        while (curr%2==0) {
            curr/=2;
            rt+=2;
        }
        for (int i=3; i<=sqrt(n); i+=2) {
            while (curr%i==0) {
                curr/=i;
                rt+=i;
            }
        }
        rt+=(curr!=1) ? curr : 0;
        return rt;
    }
};