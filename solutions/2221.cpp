// 2221. Find Triangular Sum of an Array
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for (int i=0; i<nums.size()-1; ++i)
            for (int j=1; j<nums.size()-i; ++j)
                nums[j-1]=(nums[j-1]+nums[j])%10;
        return nums[0];
    }
};