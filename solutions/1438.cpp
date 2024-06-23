// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> m;
        int i=0, j=0;
        for (; i<nums.size(); ++i) {
            m.insert(nums[i]);
            if (*m.rbegin()-*m.begin()>limit) {
                m.erase(m.find(nums[j]));
                j++;
            }
        }
        return i-j;
    }
};
