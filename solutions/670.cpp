// 670. Maximum Swap
class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num), n=s;
        sort(s.begin(), s.end(), greater<char>());

        if (s==n)
            return num;

        int i=0, j=s.length()-1;
        for (; i<s.length(); ++i)
            if (s[i]!=n[i])
                break;
        
        char lookingFor=s[i];
        for (; j>=0; --j)
            if (n[j]==lookingFor)
                break;
        swap(n[i], n[j]);
        return stoi(n);
    }
};