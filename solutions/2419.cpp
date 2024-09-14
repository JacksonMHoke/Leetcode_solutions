// 2419. Longest Subarray With Maximum Bitwise AND
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int rt=0, mx=0, curr=0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]>mx) {
                mx=nums[i];
                rt=0;
                curr=0;
            }

            curr=(nums[i]==mx) ? curr+1 : 0;
            rt=max(rt, curr);
        }
        return rt;
    }
};