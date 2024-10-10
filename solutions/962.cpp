// 962. Maximum Width Ramp
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int rt=0;
        stack<int> next_shortest;
        next_shortest.push(0);
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i]<nums[next_shortest.top()])
                next_shortest.push(i);
        }

        for (int i=nums.size()-1; i>=0 && !next_shortest.empty(); --i) {
            while (!next_shortest.empty() && nums[i]>=nums[next_shortest.top()]) {
                rt=max(rt, i-next_shortest.top());
                next_shortest.pop();
            }
        }

        return rt;
    }
};