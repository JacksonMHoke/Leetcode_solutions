// 1963. Minimum Number of Swaps to Make the String Balanced
class Solution {
public:
    int minSwaps(string s) {
        int swaps=0, brackets=0;
        for (int i=0; i<s.length(); ++i) {
            brackets+=(s[i]=='[')-(s[i]==']');
            if (brackets<0) {
                swaps++;
                brackets+=2;
            }
        }
        return swaps;
    }
};