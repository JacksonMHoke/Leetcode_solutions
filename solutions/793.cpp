// 793. Preimage Size of Factorial Zeroes Function
// Credit goes to BitcoinEvangelist https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/solutions/117649/4ms-java-math-solution/
// Could not quite figure out the solution myself, although I got close. Beautiful mathmatical solution imo.
class Solution {
public:
    int preimageSizeFZF(int k) {
        if (k < 5){
            return 5;
        }
        int d = 1;
        while (d * 5 + 1 <= k){
            d = d * 5 + 1;
        }
        if (k / d == 5){
            return 0;
        }
        return preimageSizeFZF(k % d);
    }
};