// 2779. Maximum Beauty of an Array After Applying Operation
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> sweep(*max_element(nums.begin(), nums.end())+k+2);
        for (int i=0; i<nums.size(); ++i) {
            sweep[max(0, nums[i]-k)]++;
            sweep[nums[i]+k+1]--;
        }
        int curr=0, mx=0;
        for (int i=0; i<sweep.size(); ++i) {
            curr+=sweep[i];
            mx=max(mx, curr);
        }
        return mx;
    }
};