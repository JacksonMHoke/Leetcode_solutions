// 2044. Count Number of Maximum Bitwise-OR Subsets
class Solution {
public:
    int backtrack(vector<int>& nums, int i, int curr, int mx) {
        if (curr==mx)
            return 1<<(nums.size()-i); 
        if (i==nums.size())
            return 0;
        
        return backtrack(nums, i+1, curr, mx)+backtrack(nums, i+1, curr|nums[i], mx);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int mx=0;
        for (auto num : nums)
            mx|=num;

        return backtrack(nums, 0, 0, mx);
    }
};