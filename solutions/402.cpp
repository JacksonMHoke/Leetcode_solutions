// 402. Remove K Digits
class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack;
        for (int i=0; i<num.length(); ++i) {
            while (!stack.empty() && stack.back()>num[i] && k>0) {
                stack.pop_back();
                k--;
            }
            if (!(stack.empty() && num[i]=='0'))
                stack+=num[i];
        }
        while (k-- && !stack.empty())
            stack.pop_back();
        return (stack.empty()) ? "0" : stack;
    }
};