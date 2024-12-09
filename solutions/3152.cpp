// 3152. Special Array II
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> specialStartingAt(nums.size());
        int leftmost=0;
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i-1]%2==nums[i]%2)
                leftmost=i;
            specialStartingAt[i]=leftmost;
        }
        vector<bool> rt;
        for (auto& query : queries)
            rt.push_back(specialStartingAt[query[1]]<=query[0]);
        return rt;
    }
};