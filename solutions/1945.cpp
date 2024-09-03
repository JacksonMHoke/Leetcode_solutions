// 1945. Sum of Digits of String After Convert
class Solution {
public:
    int getLucky(string s, int k) {
        string t="";
        for (auto c : s)
            t+=to_string(c-'a'+1);
        int curr=0;
        for (auto c : t)
            curr+=c-'0';
        
        while (--k) {
            int temp=0;
            while (curr) {
                temp+=curr%10;
                curr/=10;
            }
            curr=temp;
        }
        return curr;
    }
};