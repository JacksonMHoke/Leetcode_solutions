// 2116. Check if a Parentheses String Can Be Valid
class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.length()%2==1)
            return false;
        int closed=0, open=0;
        for (int i=0; i<s.length(); ++i) {
            if (locked[i]=='1' && s[i]==')')
                closed++;
            else
                open++;
            if (closed>open)
                return false;
        }

        open=0, closed=0;
        for (int i=s.length()-1; i>=0; --i) {
            if (locked[i]=='1' && s[i]=='(')
                open++;
            else
                closed++;
            if (open>closed)
                return false;
        }
        return true;
    }
};