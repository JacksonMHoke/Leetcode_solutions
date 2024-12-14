// 2762. Continuous Subarrays
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> window;
        int l=0;
        long long rt=0;
        for (int i=0; i<nums.size(); ++i) {
            window.insert(nums[i]);
            while (*window.begin()<*window.rbegin()-2)
                window.erase(window.find(nums[l++]));
            rt+=i-l+1;
        }
        return rt;
    }
};