// 1432. Max Difference You Can Get From Changing an Integer
class Solution {
public:
    int maxDiff(int num) {
        string mx=to_string(num), mn=to_string(num);
        int i=0;
        while (i<mn.length() && (mn[i]=='1' || mn[i]=='0'))
            i++;
        if (i==0)
            replace(begin(mn), end(mn), (char)mn[0], '1');
        else if (i<mn.length())
            replace(begin(mn), end(mn), (char)mn[i], '0');
        i=0;
        while (i<mx.length() && mx[i]=='9')
            i++;
        replace(begin(mx), end(mx), (i<mx.length())? mx[i]: '9', '9');
        return stoi(mx)-stoi(mn);
    }
};