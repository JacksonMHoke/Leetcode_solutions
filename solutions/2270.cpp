// 2270. Number of Ways to Split Array
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long tot=accumulate(nums.begin(), nums.end(), 0ll), rt=0, sum=0;
        for (int i=0; i<nums.size()-1; ++i) {
            sum+=nums[i];
            rt+=sum>=tot-sum;
        }
        return rt;
    }
};