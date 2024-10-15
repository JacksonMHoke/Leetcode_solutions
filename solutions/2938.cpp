// 2938. Separate Black and White Balls
class Solution {
public:
    long long minimumSteps(string s) {
        long long leftWhite=0, swaps=0;
        for (int i=0; i<s.length(); ++i) {
            if (s[i]=='0') {
                swaps+=i-leftWhite;
                leftWhite++;
            }
        }
        return swaps;
    }
};