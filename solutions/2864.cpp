// 2864. Maximum Odd Binary Number
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int i=0;
        for (int j=0; j<s.length(); ++j) {
            if (s[j]=='1') {
                swap(s[i], s[j]);
                i++;
            }
        }
        swap(s[max(0, i-1)], s[s.length()-1]);
        return s;
    }
}; 