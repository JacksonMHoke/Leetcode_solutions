// 1800. Maximum Ascending Subarray Sum
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum=nums[0], rt=nums[0];
        for (int i=1; i<nums.size(); ++i) {
            sum=(nums[i]>nums[i-1])? sum+nums[i]: nums[i];
            rt=max(rt, sum);
        }
        return rt;
    }
};