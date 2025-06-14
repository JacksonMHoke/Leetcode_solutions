// 2566. Maximum Difference by Remapping a Digit
class Solution {
public:
    int minMaxDifference(int num) {
        string mx=to_string(num), mn=to_string(num);
        replace(begin(mn), end(mn), (char)mn[0], '0');
        int i=0;
        while (i<mx.length() && mx[i]=='9')
            i++;
        replace(begin(mx), end(mx), (i<mx.length())? mx[i]: '9', '9');
        return stoi(mx)-stoi(mn);
    }
};