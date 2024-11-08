// 1829. Maximum XOR for Each Query
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size(), desired=(1<<maximumBit)-1, curr=0;
        vector<int> queries(n);
        for (int i=0; i<n; ++i) {
            curr^=nums[i];
            queries[n-1-i]=curr^desired;
        }
        return queries;
    }
};