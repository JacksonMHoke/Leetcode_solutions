// 1499. Max Value of Equation
class Solution {
    public:
        int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
            deque<pair<int, int>> mono{{points[0][1]-points[0][0], points[0][0]}};
            int rt=INT_MIN;
            for (int i=1; i<points.size(); ++i) {
                int x=points[i][0], y=points[i][1];
                while (!mono.empty() && x-mono[0].second>k)
                    mono.pop_front();
                if (!mono.empty())
                    rt=max(rt, y+x+mono[0].first);
                while (!mono.empty() && y-x>=mono.back().first)
                    mono.pop_back();
                mono.push_back({y-x, x});
            }
            return rt;
        }
    };