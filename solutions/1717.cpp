// 1717. Maximum Score From Removing Substrings
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char first='a', second='b';
        if (y>x) {
            swap(first, second);
            swap(x, y);
        }
        stack<char> st;
        int rt=0;
        for (int i=0; i<s.length(); ++i) {
            if (!st.empty() && st.top()==first && s[i]==second) {
                rt+=x;
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        stack<char> st2;
        while (!st.empty()) {
            if (!st2.empty() && st.top()==second && st2.top()==first) {
                rt+=y;
                st.pop();
                st2.pop();
            } else {
                st2.push(st.top());
                st.pop();
            }
        }
        return rt;
    }
};