// 2958. Length of Longest Subarray With at Most K Frequency
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0, r=0;
        int rt=0;
        unordered_map<int, int> occurences;
        while (r<nums.size()) {
            while (r<nums.size() && occurences[nums[r]]+1<=k)
                ++occurences[nums[r++]];

            if (r>=nums.size()-1)
                return max(rt, r-l);
            
            rt=max(rt, r-l);

            while (nums[l]!=nums[r])
                --occurences[nums[l++]];
            --occurences[nums[l++]];
        }
        return rt;
    }
};