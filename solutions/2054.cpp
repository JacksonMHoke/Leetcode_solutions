// 2054. Two Best Non-Overlapping Events
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<pair<int, int>> mx(events.size());
        sort(events.begin(), events.end(), [](const vector<int>& lhs, const vector<int>& rhs) { return lhs[0]<rhs[0]; });
        mx.back()={events.back()[0], events.back()[2]};
        for (int i=events.size()-2; i>=0; --i)
            mx[i]={events[i][0], max(events[i][2], mx[i+1].second)};

        sort(events.begin(), events.end(), [](const vector<int>& lhs, const vector<int>& rhs) { return lhs[1]<rhs[1]; });
        int r=0, rt=mx[0].second, mxSoFar=0;
        for (int i=0; i<events.size(); ++i) {
            mxSoFar=max(mxSoFar, events[i][2]);
            while (r<events.size() && mx[r].first<=events[i][1])
                r++;
            if (r>=events.size()) {
                rt=max(rt, mxSoFar);
                break;
            }
            rt=max(rt, mxSoFar+mx[r].second);
        }
        return rt;
    }
};