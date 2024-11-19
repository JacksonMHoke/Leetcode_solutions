// 2461. Maximum Sum of Distinct Subarrays With Length K
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long rt=0, sum=0;
        int l=0;
        unordered_map<int, int> freq;
        for (int i=0; i<nums.size(); ++i) {
            freq[nums[i]]++;
            sum+=nums[i];
            while (freq[nums[i]]>1 || i-l+1>k) {
                freq[nums[l]]--;
                sum-=nums[l];
                l++;
            }

            if (i-l+1==k && rt<sum)
                rt=sum;
        }
        return rt;
    }
};