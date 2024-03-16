//218. The Skyline Problem
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> rt;
        priority_queue<pair<int, long>> pq;
        pq.push({0, INT_MAX});
        int height=0;
        int end=INT_MAX;
        for (int i=0; i<buildings.size(); ++i) {
            int num_same=0;
            while (i+1<buildings.size() && buildings[i][0]==buildings[i+1][0]) {
                ++num_same;
                if (buildings[i][2]>buildings[i+1][2])
                    swap(buildings[i], buildings[i+1]);
                ++i;
            }
            if (buildings[i][0]>end) {
                while (pq.top().second<=end)
                    pq.pop();
                if (pq.top().first<height)
                    rt.push_back({end, pq.top().first});
                height=pq.top().first;
                end=pq.top().second;
                i--;
                continue;
            } else if (buildings[i][2]>height) {
                height=buildings[i][2];
                end=buildings[i][1];
                rt.push_back({buildings[i][0], height});
            }
            for (; num_same>=0; --num_same) 
                pq.push({buildings[i-num_same][2], buildings[i-num_same][1]});
        }

        while (!pq.empty()) {
            if (pq.top().second>end) {
                if (pq.top().first<height)
                    rt.push_back({end, pq.top().first});
                height=pq.top().first;
                end=pq.top().second;
            }
            pq.pop();
            if (!pq.empty() && end==INT_MAX)
                rt.push_back({INT_MAX, 0});
        }

        return rt;
    }
};