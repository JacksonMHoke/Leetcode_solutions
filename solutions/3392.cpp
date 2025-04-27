// 3392. Count Subarrays of Length Three With a Condition
class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int rt=0;
            for (int i=1; i<nums.size()-1; ++i)
                rt+=(2*(nums[i-1]+nums[i+1])==nums[i]);
            return rt;
        }
    };