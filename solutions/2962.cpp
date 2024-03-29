// 2962. Count Subarrays Where Max Element Appears at Least K Times
//Credit goes to https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/solutions/4384405/java-c-python-sliding-window/?envType=daily-question&envId=2024-03-29

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long rt=0;
        int max = *max_element(nums.begin(), nums.end());
        int l=0, n=nums.size(), freq=0;
        for (int r=0; r<n; ++r) {
            freq+=max==nums[r];
            while (freq>=k)
                freq-=nums[l++]==max;
            rt+=l;
        }
        return rt;
    }
};