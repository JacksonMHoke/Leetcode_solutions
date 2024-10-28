// 2501. Longest Square Streak in an Array
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int rt=0;
        for (int i=0; i<nums.size(); ++i) {
            if (!num_set.contains(nums[i]))
                continue;
            int curr=nums[i];
            int len=1;
            while (curr<46341 && num_set.contains(curr*curr)) {
                num_set.erase(curr);
                len++;
                curr=curr*curr;
            }
            rt=max(rt, len);
        }
        return (rt>1) ? rt : -1;
    }
};