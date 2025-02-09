// 2364. Count Number of Bad Pairs
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        long long rt=0;
        for (int i=0; i<nums.size(); ++i) {
            rt+=i-mp[nums[i]-i]++;
        }
        return rt;
    }
};