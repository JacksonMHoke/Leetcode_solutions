// 2342. Max Sum of a Pair With Equal Sum of Digits
class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            unordered_map<int, int> mp;
            int rt=-1;
            for (int i=0; i<nums.size(); ++i) {
                int val=nums[i], sum=0;
                while (val) {
                    sum+=val%10;
                    val/=10;
                }
                if (mp[sum]>0)
                    rt=max(rt, mp[sum]+nums[i]);
                mp[sum]=max(mp[sum], nums[i]);
            }
            return rt;
        }
    };