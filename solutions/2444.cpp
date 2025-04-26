// 2444. Count Subarrays With Fixed Bounds
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long rt=0;
        int lastMin=-1, lastMax=-1, lastGreater=-1, lastLess=-1;
        for (int i=0; i<nums.size(); ++i) {
            lastMin=(nums[i]==minK)?i:lastMin;
            lastMax=(nums[i]==maxK)?i:lastMax;
            lastGreater=(nums[i]>maxK)?i:lastGreater;
            lastLess=(nums[i]<minK)?i:lastLess;

            rt+=max(min(lastMin, lastMax)-max(lastGreater, lastLess), 0);
        }
        return rt;
    }
};