// 862. Shortest Subarray with Sum at Least K
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long, int>> q;
        long sum=0;
        int rt=INT_MAX;
        for (int i=0; i<nums.size(); ++i) {
            sum+=nums[i];
            if (sum>=k)
                rt=min(rt, i+1);
            while (!q.empty() && sum-q.front().first>=k) {
                rt=min(rt, i-q.front().second);
                q.pop_front();
            }
            while (!q.empty() && q.back().first>=sum) 
                q.pop_back();
            q.push_back({sum, i});
        }
        return (rt==INT_MAX) ? -1 : rt;
    }
};