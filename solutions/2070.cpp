// 2070. Most Beautiful Item for Each Query
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [](vector<int>& lhs, vector<int>& rhs) { return lhs[0]<rhs[0]; });
        for (int i=1; i<items.size(); ++i)
            items[i][1]=max(items[i][1], items[i-1][1]);
        vector<int> rt;
        for (auto query : queries) {
            auto it=upper_bound(items.begin(), items.end(), query, [](int lhs, vector<int>& rhs) { return lhs<rhs[0]; });
            if (it==items.begin())
                rt.push_back(0);
            else
                rt.push_back((*(it-1))[1]);
        }
        return rt;
    }
};