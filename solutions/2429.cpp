// 2429. Minimize XOR
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ones1=__builtin_popcount(num1), ones2=__builtin_popcount(num2), x=0;
        for (int i=0; i<ones1-ones2; ++i)
            num1-=num1&-num1;
        x=num1;
        for (int i=0; i<ones2-ones1; ++i)
            x+=(x+1)&-(x+1);
        return x;
    }
};