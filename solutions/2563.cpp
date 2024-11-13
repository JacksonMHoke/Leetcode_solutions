// 2563. Count the Number of Fair Pairs
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long rt=0;
        for (auto num : nums) {
            auto l=lower_bound(nums.begin(), nums.end(), lower-num);
            auto u=upper_bound(nums.begin(), nums.end(), upper-num);
            rt+=u-l-(num>=lower-num && num<=upper-num);
        }
        return rt/2;
    }
};