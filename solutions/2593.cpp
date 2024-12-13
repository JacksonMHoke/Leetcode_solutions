// 2593. Find Score of an Array After Marking All Elements
class Solution {
public:
    long long findScore(vector<int>& nums) {
        set<pair<int, int>> unmarked;
        long long rt=0;
        for (int i=0; i<nums.size(); ++i)
            unmarked.insert({nums[i], i});
        while (!unmarked.empty()) {
            auto [val, i]=*unmarked.begin();
            rt+=val;
            unmarked.erase(unmarked.begin());
            if (i+1<nums.size())
                unmarked.erase({nums[i+1], i+1});
            if (i-1>=0)
                unmarked.erase({nums[i-1], i-1});
        }
        return rt;
    }
};