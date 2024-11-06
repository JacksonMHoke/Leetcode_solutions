// 3011. Find if Array Can Be Sorted
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int prevMax=0;
        int i=0;
        while (i<nums.size()) {
            int currMax=nums[i], currMin=nums[i], bits=__builtin_popcount(nums[i]);
            i++;
            while (i<nums.size() && __builtin_popcount(nums[i])==bits) {
                currMax=max(currMax, nums[i]);
                currMin=min(currMin, nums[i]);
                i++;
            }
            if (currMin<prevMax)
                return false;
            prevMax=max(currMax, prevMax);
        }
        return true;
    }
};