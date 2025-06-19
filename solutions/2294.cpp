// 2294. Partition Array Such That Maximum Difference Is K
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int rt=1, mn=nums[0];
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]>mn+k) {
                mn=nums[i];
                rt++;
            }
        }
        return rt;
    }
};