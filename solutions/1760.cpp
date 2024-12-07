// 1760. Minimum Limit of Balls in a Bag
class Solution {
public:
    bool check(vector<int>& nums, int maxOps, int limit) {
        for (int i=0; i<nums.size() && maxOps>=0 && nums[i]>limit; ++i) {
            if (nums[i]>limit)
                maxOps-=(nums[i]-1)/limit;
        }
        return maxOps>=0;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(nums.begin(), nums.end(), [](const int lhs, const int rhs){ return rhs<lhs; });
        int low=1, high=nums[0];
        while (low<high) {
            int mid=low+(high-low)/2;
            if (check(nums, maxOperations, mid))
                high=mid;
            else
                low=mid+1;
        }
        return high;
    }
};