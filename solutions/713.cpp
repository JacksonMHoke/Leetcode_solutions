//713. Subarray Product Less Than K
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k<1)
            return 0;

        int product=1;
        int end=0;
        int rt=0;
        nums.push_back(1);
        for (int i=0; i<nums.size(); ++i) {
            end=max(i, end);
            while (product<k && end<nums.size())
                product*=nums[end++];
            if (end>i)
                product/=nums[--end];
            if (nums[i]<k) {
                rt+=end-i;
                product/=nums[i];
            }
        }
        nums.pop_back();
        return rt;
    }
};