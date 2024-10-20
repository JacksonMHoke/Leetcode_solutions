// 1106. Parsing A Boolean Expression
class Solution {
public:
    bool helper(string& exp, int& i) {
        if (exp[i]=='t')
            return true;
        else if (exp[i]=='f')
            return false;

        vector<bool> params;
        char curr=exp[i];
        if (exp[i]=='|' || exp[i]=='!' || exp[i]=='&') {
            for (; i<exp.length() && exp[i]!=')'; ++i) {
                if (exp[i]=='(' || exp[i]==',')
                    params.push_back(helper(exp, ++i));
            }
        }

        bool rt=params[0];
        for (int j=0; j<params.size(); ++j) {
            if (curr=='&')
                rt&=params[j];
            else if (curr=='|')
                rt|=params[j];
        }
        return (curr=='!') ? !rt : rt;
    }

    bool parseBoolExpr(string expression) {
        int i=0;
        return helper(expression, i);
    }
};