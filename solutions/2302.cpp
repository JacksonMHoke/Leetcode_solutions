// 2302. Count Subarrays With Score Less Than K
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            long long rt=0, curr=0;
            for (long long l=0, r=0; r<nums.size(); ++r) {
                curr+=nums[r];
                while (curr*(r-l+1)>=k)
                    curr-=nums[l++];
                rt+=r-l+1;
            }
            return rt;
        }
    };