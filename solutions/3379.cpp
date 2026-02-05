// 3379. Transformed Array
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> rt(n);
        for (int i=0; i<n; ++i) {
            rt[i]=nums[(i+nums[i]+n*100)%n];
        }
        return rt;
    }
};