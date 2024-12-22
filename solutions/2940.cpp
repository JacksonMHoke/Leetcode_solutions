// 2940. Find Building Where Alice and Bob Can Meet
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> rt(queries.size());
        vector<array<int, 3>> qs;
        for (int i=0; i<queries.size(); ++i)
            qs.push_back({min(queries[i][0], queries[i][1]), max(queries[i][1], queries[i][0]), i});
        sort(qs.begin(), qs.end(), [](const array<int, 3>& lhs, const array<int, 3>& rhs){ return lhs[1]<rhs[1]; });
        
        deque<pair<int, int>> mono;
        int monoIdx=heights.size()-1;
        for (int i=queries.size()-1; i>=0; --i) {
            auto [l, r, idx]=qs[i];
            if (l==r) {
                rt[idx]=l;
                continue;
            }
            while (monoIdx>=0 && monoIdx>=r) {
                while (!mono.empty() && mono.front().first<=heights[monoIdx])
                    mono.pop_front();
                mono.push_front({heights[monoIdx], monoIdx});
                monoIdx--;
            }
            auto it=upper_bound(mono.begin(), mono.end(), heights[l], [](int lhs, const pair<int, int>& rhs) { return lhs<rhs.first; });
            rt[idx]=(it!=mono.end()) ? it->second : -1;
        }

        return rt;
    }
};