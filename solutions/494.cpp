class Solution {
public:
    int backtrack(vector<int>& nums, vector<int>& suffix, vector<vector<int>>& dp, int target, int i) {
        if (i==nums.size())
            return target==0;
        if (abs(target)>suffix[i])
            return 0;
        if (dp[i][target+1000]!=-1)
            return dp[i][target+1000];
        dp[i][target+1000]=backtrack(nums, suffix, dp, target-nums[i], i+1)+backtrack(nums, suffix, dp, target+nums[i], i+1);
        return dp[i][target+1000];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> suffix(nums.size());
        suffix.back()=nums.back();
        for (int i=nums.size()-2; i>=0; --i)
            suffix[i]=suffix[i+1]+nums[i];
        vector<vector<int>> dp(nums.size(), vector<int>(2001, -1));
        return backtrack(nums, suffix, dp, target, 0);
    }
};