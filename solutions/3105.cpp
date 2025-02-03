// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=0, dec=0, rt=1;
        for (int i=1; i<nums.size(); ++i) {
            inc=(nums[i]>nums[i-1])? inc+1: 0;
            dec=(nums[i]<nums[i-1])? dec+1: 0;
            rt=max({rt, inc+1, dec+1});
        }
        return rt;
    }
};