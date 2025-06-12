// 3423. Maximum Difference Between Adjacent Elements in a Circular Array
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int rt=abs(nums[0]-nums.back());
        for (int i=0; i<nums.size()-1; ++i)
            rt=max(rt, abs(nums[i]-nums[i+1]));
        return rt;
    }
};