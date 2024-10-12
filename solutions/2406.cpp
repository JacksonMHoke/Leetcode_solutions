// 2406. Divide Intervals Into Minimum Number of Groups
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int groups=0, maxGroups=1;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> endings;
        for (int i=0; i<intervals.size(); ++i) {
            while (!endings.empty() && endings.top()<intervals[i][0]) {
                endings.pop();
                groups--;
            }

            endings.push(intervals[i][1]);
            groups++;
            maxGroups=max(maxGroups, groups);
        }
        return maxGroups;
    }
};