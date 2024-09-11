// 2220. Minimum Bit Flips to Convert Number
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start^goal, i=0;
        for (; x; ++i)
            x-=x&-x;
        return i;
    }
};