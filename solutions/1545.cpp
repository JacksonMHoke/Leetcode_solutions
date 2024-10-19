// 1545. Find Kth Bit in Nth Binary String
class Solution {
public:
    char findKthBit(int n, int k) {
        if (n==1)
            return '0';

        if (k==(1<<(n-1)))
            return '1';

        char rt;
        if (k<(1<<(n-1)))
            rt=findKthBit(n-1, k);
        else
            rt=(findKthBit(n-1, (1<<n)-k)=='0') ? '1' : '0';
        return rt;
    }
};