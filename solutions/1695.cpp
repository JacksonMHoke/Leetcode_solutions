// 1695. Maximum Erasure Value
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        bool used[10001]{false};
        int l=0, r=0, n=nums.size();
        int sum=0;
        int rt=0;
        while (r<n) {
            while (used[nums[r]]) {
                sum-=nums[l];
                used[nums[l++]]=false;
            }
            used[nums[r]]=true;
            sum+=nums[r++];
            rt=max(sum, rt);
        }
        return rt;
    }
};