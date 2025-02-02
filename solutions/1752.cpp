// 1752. Check if Array Is Sorted and Rotated
class Solution {
public:
    bool check(vector<int>& nums) {
        int dec=nums.back()>nums[0];
        for (int i=0; i<nums.size()-1; ++i)
            dec+=nums[i]>nums[i+1];
        return dec<2;
    }
};