// 386. Lexicographical Numbers
class Solution {
public:
    void helper(vector<int>& rt, int curr, int n) {
        for (int i=0; i<10 && curr+i<=n; ++i) {
            if (curr+i==0)
                continue;
            rt.push_back(curr+i);
            helper(rt, (curr+i)*10, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> rt;
        helper(rt, 0, n);
        return rt;
    }
};