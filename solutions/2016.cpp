// 2016. Maximum Difference Between Increasing Elements
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn=nums[0]+1, rt=-1;
        for (auto num : nums) {
            rt=max(rt, num-mn);
            mn=min(mn, num);
        }
        return (rt>0)? rt: -1;
    }
};